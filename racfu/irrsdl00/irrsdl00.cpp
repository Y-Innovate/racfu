#include "irrsdl00.hpp"

namespace RACFu {
void IRRSDL00::callIRRSDL00(keyring_extract_arg_area_t *p_arg_area,
                            uint32_t *p_parmlist_version, void *p_parmlist) {
  uint32_t nNumParms = 14;

  IRRSDL64(&nNumParms, &p_arg_area->args.RACF_work_area[0],
           p_arg_area->args.ALET_SAF_rc, &p_arg_area->args.SAF_rc,
           p_arg_area->args.ALET_RACF_rc, &p_arg_area->args.RACF_rc,
           p_arg_area->args.ALET_RACF_rsn, &p_arg_area->args.RACF_rsn,
           &p_arg_area->args.function_code, &p_arg_area->args.attributes,
           &p_arg_area->args.RACF_user_id[0], &p_arg_area->args.ring_name[0],
           p_parmlist_version, p_parmlist);
}

void IRRSDL00::extractKeyring(SecurityRequest &request,
                              keyring_extract_arg_area_t *p_arg_area_keyring) {
  uint32_t parmlist_version = 0;

  auto result_unique_ptr =
      std::make_unique<char[]>(sizeof(keyring_extract_parms_results_t));
  std::memset(result_unique_ptr.get(), 0,
              sizeof(keyring_extract_parms_results_t));
  p_arg_area_keyring->args.p_result_buffer =
      reinterpret_cast<keyring_extract_parms_results_t *>(
          result_unique_ptr.get());
  p_arg_area_keyring->args.p_result_buffer->result_buffer_length =
      sizeof(keyring_extract_parms_results_t);
  request.setRawResultLength(
      p_arg_area_keyring->args.p_result_buffer->result_buffer_length);

  keyring_extract_parms_results_t *p_result_buffer =
      p_arg_area_keyring->args.p_result_buffer;

  cddlx_get_ring_t *p_parm_get_ring = &p_result_buffer->result_buffer_get_ring;

  p_arg_area_keyring->args.function_code = 0x0D;
  p_arg_area_keyring->args.attributes    = 0;

  p_parm_get_ring->cddlx_ring_res_len    = RING_INFO_BUFFER_SIZE;
  p_parm_get_ring->cddlx_ring_res_ptr =
      &p_result_buffer->union_ring_result.ring_result;

  Logger::getInstance().debug("cddlx_get_ring_t before call");
  Logger::getInstance().hexDump(reinterpret_cast<char *>(p_parm_get_ring),
                                sizeof(cddlx_get_ring_t));

  IRRSDL00::callIRRSDL00(p_arg_area_keyring, &parmlist_version,
                         p_parm_get_ring);

  Logger::getInstance().debug("cddlx_get_ring_t after call");
  Logger::getInstance().hexDump(reinterpret_cast<char *>(p_parm_get_ring),
                                sizeof(cddlx_get_ring_t));

  Logger::getInstance().debug("Ring result (first 256)");
  Logger::getInstance().hexDump(
      reinterpret_cast<char *>(p_parm_get_ring->cddlx_ring_res_ptr), 256);

  if (p_arg_area_keyring->args.SAF_rc <= 4 &&
      p_arg_area_keyring->args.RACF_rc <= 4 &&
      p_arg_area_keyring->args.RACF_rsn == 0) {
    ring_result_t *p_ring_result =
        &p_result_buffer->union_ring_result.ring_result;

    int ring_count = ntohl(p_ring_result->ring_count);

    unsigned char *work =
        reinterpret_cast<unsigned char *>(&p_ring_result->ring_info);
    int help_len = 0;

    for (int i = 0; i < ring_count; i++) {
      // Count ring owner
      help_len += 1 + *work;
      work += 1 + *work;

      // Count ring name
      help_len += 1 + *work;
      work += 1 + *work;

      // Count cert count
      help_len += 4;
      unsigned int certCount = ntohl(*(reinterpret_cast<uint32_t *>(work)));
      work += 4;

      p_result_buffer->cert_count += certCount;

      for (int j = 0; j < certCount; j++) {
        // Count cert owner
        help_len += 1 + *work;
        work += 1 + *work;

        // Count cert name
        help_len += 1 + *work;
        work += 1 + *work;
      }
    }

    p_result_buffer->ring_info_length = help_len;

    if (p_result_buffer->cert_count > 0) {
      // Reallocate memory with a larger block to include DataGetFirst results
      // per cert
      int result_len =
          p_result_buffer->result_buffer_length +
          (p_result_buffer->cert_count * sizeof(get_cert_buffer_t));
      auto result2_unique_ptr = std::make_unique<char[]>(result_len);
      p_result_buffer = reinterpret_cast<keyring_extract_parms_results_t *>(
          result2_unique_ptr.get());
      std::memset(p_result_buffer, 0, result_len);
      std::memcpy(p_result_buffer, p_arg_area_keyring->args.p_result_buffer,
                  sizeof(keyring_extract_parms_results_t));
      result_unique_ptr.reset();
      p_arg_area_keyring->args.p_result_buffer = p_result_buffer;
      p_result_buffer->result_buffer_length    = result_len;
      p_result_buffer->result_buffer_get_ring.cddlx_ring_res_ptr =
          &p_result_buffer->union_ring_result.ring_result;
      p_ring_result = &p_result_buffer->union_ring_result.ring_result;

      get_cert_buffer_t *p_get_cert_buffer =
          reinterpret_cast<get_cert_buffer_t *>(
              (((uint64_t)p_result_buffer) +
               sizeof(keyring_extract_parms_results_t)));
      p_result_buffer->p_get_cert_buffer = p_get_cert_buffer;

      int get_cert_index                 = 0;

      bool keep_going                    = true;

      work = reinterpret_cast<unsigned char *>(&p_ring_result->ring_info);

      for (int i = 0; keep_going && i < ring_count; i++) {
        // Ring owner
        work += 1 + *work;

        // Ring name
        work += 1 + *work;

        // Cert count
        unsigned int certCount = ntohl(*(reinterpret_cast<uint32_t *>(work)));
        work += 4;

        for (int j = 0; keep_going && j < certCount; j++) {
          // Cert owner
          unsigned char *p_owner = work;
          work += 1 + *work;

          // Cert name
          unsigned char *p_label = work;
          work += 1 + *work;

          IRRSDL00::extractCert(request, p_arg_area_keyring, p_get_cert_buffer,
                                p_owner, p_label);

          if (p_arg_area_keyring->args.SAF_rc <= 4 &&
              p_arg_area_keyring->args.RACF_rc <= 4 &&
              p_arg_area_keyring->args.RACF_rsn == 0) {
            get_cert_index++;
            p_get_cert_buffer = reinterpret_cast<get_cert_buffer_t *>(
                (((uint64_t)p_get_cert_buffer) + sizeof(get_cert_buffer_t)));
          } else {
            keep_going = false;
          }
        }
      }

      request.setRawResultPointer(result2_unique_ptr.get());
      result2_unique_ptr.release();
      request.setRawResultLength(
          p_arg_area_keyring->args.p_result_buffer->result_buffer_length);
    } else {
      request.setRawResultPointer(result_unique_ptr.get());
      result_unique_ptr.release();
      request.setRawResultLength(
          p_arg_area_keyring->args.p_result_buffer->result_buffer_length);
    }
  } else {
    request.setRawResultPointer(result_unique_ptr.get());
    result_unique_ptr.release();
    request.setRawResultLength(
        p_arg_area_keyring->args.p_result_buffer->result_buffer_length);
  }

  request.setSAFReturnCode(p_arg_area_keyring->args.SAF_rc);
  request.setRACFReturnCode(p_arg_area_keyring->args.RACF_rc);
  request.setRACFReasonCode(p_arg_area_keyring->args.RACF_rsn);
}

void IRRSDL00::extractCert(const SecurityRequest &request,
                           keyring_extract_arg_area_t *p_arg_area_keyring,
                           get_cert_buffer_t *p_get_cert_buffer,
                           unsigned char *p_owner, unsigned char *p_label) {
  uint32_t parmlist_version_ = 1;

  keyring_extract_parms_results_t *p_result_buffer =
      p_arg_area_keyring->args.p_result_buffer;

  cddlx_get_cert_t *p_parm_get_cert =
      &p_get_cert_buffer->result_buffer_get_cert;

  p_arg_area_keyring->args.function_code       = 1;
  p_arg_area_keyring->args.attributes          = 0xA0000000;

  p_result_buffer->handle_map.cddlx_predicates = 1;
  p_result_buffer->handle_map.cddlx_attr_id    = 1;  // match on label
  p_result_buffer->handle_map.cddlx_attr_len   = *p_label;
  p_result_buffer->handle_map.cddlx_attr_ptr   = &p_label[1];

  p_parm_get_cert->cddlx_res_handle            = &p_result_buffer->handle_map;
  p_parm_get_cert->cddlx_cert_len              = CERT_BUFFER_SIZE;
  p_parm_get_cert->cddlx_cert_ptr =
      reinterpret_cast<unsigned char *>(&p_get_cert_buffer->cert_buffer[0]);
  p_parm_get_cert->cddlx_pk_len = PKEY_BUFFER_SIZE;
  p_parm_get_cert->cddlx_pk_ptr =
      reinterpret_cast<unsigned char *>(&p_get_cert_buffer->pkey_buffer[0]);
  p_parm_get_cert->cddlx_label_len = LABEL_BUFFER_SIZE;
  p_parm_get_cert->cddlx_label_ptr =
      reinterpret_cast<unsigned char *>(&p_get_cert_buffer->label_buffer[0]);
  p_parm_get_cert->cddlx_racf_userid[0] = 8;
  p_parm_get_cert->cddlx_sdn_len        = SDN_BUFFER_SIZE;
  p_parm_get_cert->cddlx_sdn_ptr =
      reinterpret_cast<unsigned char *>(&p_get_cert_buffer->cert_sdn_buffer[0]);
  p_parm_get_cert->cddlx_recid_len = RECID_BUFFER_SIZE;
  p_parm_get_cert->cddlx_recid_ptr = reinterpret_cast<unsigned char *>(
      &p_get_cert_buffer->cert_recid_buffer[0]);

  Logger::getInstance().debug("Keyring extract request buffer:");
  Logger::getInstance().hexDump(reinterpret_cast<char *>(p_arg_area_keyring),
                                request.getRawRequestLength());

  Logger::getInstance().debug("cddlx_get_cert_t before call");
  Logger::getInstance().hexDump(reinterpret_cast<char *>(p_parm_get_cert),
                                sizeof(cddlx_get_cert_t));

  IRRSDL00::callIRRSDL00(p_arg_area_keyring, &parmlist_version_,
                         p_parm_get_cert);

  Logger::getInstance().debug("cddlx_get_cert_t after call");
  Logger::getInstance().hexDump(reinterpret_cast<char *>(p_parm_get_cert),
                                sizeof(cddlx_get_cert_t));
}
}  // namespace RACFu

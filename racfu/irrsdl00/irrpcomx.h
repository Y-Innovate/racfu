??=ifdef __COMPILER_VER__                                                       
  ??=pragma filetag("IBM-1047")                                                 
  ??=pragma nosequence                                                          
  ??=pragma nomargins                                                           
??=endif                                                                        
                                                                                
#ifndef __irrpcomx__                                                            
#define __irrpcomx__                                                            
                                                                                
#include <ihachdr.h>                                                            
IHACHDR_PRAGMA_DISABLE_CCN6608                                                  
#pragma pack(1)                                                                 
                                                                                
 /* Header built on 20245. CBGENC compile date 20027                 */         
 /****START OF SPECIFICATIONS******************************************         
*                                                                               
*  $MAC (IRRPCOMX) COMP(SC1BN) PROD(SAF):                                       
*                                                                               
*01* MACRO NAME: irrpcomx                                                       
*                                                                               
*01* Struct Name: COMPX                                                         
*                                                                               
*01* DESCRIPTIVE NAME: OMVS Common Security Parameter List (64 bit)             
*                                                                               
*02*   ACRONYM: COMPX                                                           
*                                                                    */         
 /*01* PROPRIETARY STATEMENT=                                        */         
 /***PROPRIETARY_STATEMENT********************************************/         
 /*                                                                  */         
 /*                                                                  */         
 /* LICENSED MATERIALS - PROPERTY OF IBM                             */         
 /* 5650-ZOS COPYRIGHT IBM CORP. 2020, 2021                          */         
 /*                                                                  */         
 /* STATUS= HBB77D0                                                  */         
 /*                                                                  */         
 /***END_OF_PROPRIETARY_STATEMENT*************************************/         
 /*                                                                  */         
 /*01* EXTERNAL CLASSIFICATION: PI                               @L9C*/         
 /*01* END OF EXTERNAL CLASSIFICATION:                               */         
 /*                                                                             
*01* FUNCTION:                                                                  
*                                                                               
*    This file contains the mapping of the common input                         
*    parameter list for OMVS SAF and RACF routers. It also has                  
*    the input parameter lists for each of the 64 bit OMVS security             
*    service routines. The input parameter lists in this file are:              
*                                                                               
*    DSECT NAME   STUB NAME      SECURITY FUNCTION                              
*                                                                               
*      COMPX      all         Common Security                                   
*                                                                               
*                                                                               
*      CDDLX      IRRSDL00    CDSA Data Lib Service (64 bit)                    
*      GSEC       IRRSGS00    Generic Security API                @L1A          
*                                                                               
*01* SIZE: Release dependent. Refer to the mapping.                             
*            compx                       -- X'0070' bytes                       
*            cddlx_attributes_map        -- X'0004' bytes                       
*            cddlx_attr_map_dataget      -- X'0001' bytes                       
*            cddlx_attr_map_newring      -- X'0001' bytes                       
*            cddlx_attr_map_dataput      -- X'0001' bytes                       
*            cddlx_attr_map_dataremove   -- X'0001' bytes                       
*            cddlx_attr_map_incserialnum -- X'0001' bytes                       
*            cddlx_abort                 -- X'0008' bytes                       
*            cddlx_get_cert              -- X'0074' bytes                       
*            cddlx_crt_status            -- X'0010' bytes                       
*            cddlx_get_update            -- X'0004' bytes                       
*            cddlx_isn                   -- X'0018' bytes                       
*            cddlx_put_cert              -- X'0044' bytes                       
*            cddlx_remove_cert           -- X'001C' bytes                       
*            cddlx_alter_cert            -- X'002C' bytes                       
*            cddlx_get_ring              -- X'0010' bytes                       
*            cddlx_handle_map            -- X'0018' bytes                       
*            gsec_retname                -- X'0030' bytes                       
*            gsec31_retname              -- X'0018' bytes                       
*            gsec_gssapi_common          -- X'0020' bytes                       
*            gsec31_gssapi_common        -- X'0010' bytes                       
*            gsec_initseccontext         -- X'0060' bytes                       
*            gsec31_initseccontext       -- X'0030' bytes                       
*            gsec_contseccontext         -- X'0048' bytes                       
*            gsec31_contseccontext       -- X'0024' bytes                       
*            gsec_accseccontext          -- X'0060' bytes                       
*            gsec31_accseccontext        -- X'0030' bytes                       
*            gsec_delseccontext          -- X'0028' bytes                       
*            gsec31_delseccontext        -- X'0014' bytes                       
*            gsec_relcred                -- X'0028' bytes                       
*            gsec31_relcred              -- X'0014' bytes                       
*            gsec_getmic                 -- X'0040' bytes                       
*            gsec31_getmic               -- X'0020' bytes                       
*            gsec_vermic                 -- X'0048' bytes                       
*            gsec31_vermic               -- X'0024' bytes                       
*            gsec_wrapmsg                -- X'0050' bytes                       
*            gsec31_wrapmsg              -- X'0028' bytes                       
*            gsec_unwrapmsg              -- X'0048' bytes                       
*            gsec31_unwrapmsg            -- X'0024' bytes                       
*            gsec_exportseccontext       -- X'0030' bytes                       
*            gsec31_exportseccontext     -- X'0018' bytes                       
*            gsec_importseccontext       -- X'0038' bytes                       
*            gsec31_importseccontext     -- X'001C' bytes                       
*            gsec_exportcred             -- X'0030' bytes                       
*            gsec31_exportcred           -- X'0018' bytes                       
*            gsec_importcred             -- X'0038' bytes                       
*            gsec31_importcred           -- X'001C' bytes                       
*            gsec_acquirecred            -- X'0040' bytes                       
*            gsec31_acquirecred          -- X'0020' bytes                       
*            gsec_passticket_parms       -- X'0020' bytes                       
*            gsec31_passticket_parms     -- X'0010' bytes                       
*                                                                               
*01* POINTED TO BY: Address of COMPX is passed in register 1                    
*                   when invoking OMVSsecurity functions.                       
*                                                                               
*01* CREATED BY: Invoker of OMVS security functions.                            
*                                                                               
*01* DELETED BY: Invoker of OMVS security functions.                            
*                                                                               
*01* STORAGE ATTRIBUTES:                                                        
*02*   SUBPOOL:  N/A                                                            
*02*   KEY:      Any                                                            
*02*   RESIDENCY: Invoker's primary address space                               
*                                                                               
*01* FREQUENCY: N/A                                                             
*                                                                               
*01* SERIALIZATION: N/A                                                         
*                                                                               
*01* DEPENDENCIES: None                                                         
*                                                                               
*01* NOTES:                                                                     
*  This part was heavily restructured in z/OS 2.5 to make it                    
*   compatible with the C-header generation utility used during build.          
*   o The tool requires that all of the 'main' plist components                 
*     (COMPX, CDDL, GSEC) be contiguous, and not separated                      
*     by constants or parameter list sub-mappings. The 'main' plist             
*     components are those which are specified on the CALL statement.           
*   o The ASM portion is unaffected by these changes.                           
*   o To add a new service to the PLX mapping:                                  
*     - Locate 'COMPX sub-declares'.                                            
*     - Change the previous semi-colon to 'CompX_Term'                          
*     - Add the main plist                                                      
*     - End it with a semi-colon                                                
*   o All constants and additional data mappings should be added                
*      to the very end of the macro.                              @LFC          
*                                                                               
*  Note: The build process puts the generated C file in:                        
*        - SYS1.SIEAHDR.H                                                       
*        - /usr/include/zos with a ".h" suffix                                  
*                                                                               
*01* COMPONENT:   SAF (SC1BN)                                                   
*                                                                               
*01* DISTRIBUTION LIBRARY: SYS1.SIEAHDR.H and /usr/include/zos                  
*                                                                               
*01* EYE-CATCHER: None - this is not a control block definition.                
*02*   OFFSET:  N/A                                                             
*02*   LENGTH:  N/A                                                             
*                                                                               
*01* CHANGE-ACTIVITY:                                                           
*  $L0=64SAF    HBB7709 001114 PDER1   64 Bit support                           
*  $L1=KRBGSS   HBB7709 020506 PDER1   Kerberos GSSAPI support   @L1A           
*  $P1=PJK0835  HBB7709 030825 PDER1   PTM PJK0835               @P1A           
*  $L2=PTCS     HBB7720 040111 PDMO1   PAssTicket Enhancements   @L2A           
*  $P2=MG05219  HBB7730 051101 PDAWS1: Defect MG05219            @P2A           
*  $L3=PKIS9    HBB7740 060127 PDTCG1: Writeable Keyring         @L3A           
*  $L4=PKIS9    HBB7740 060406 PDRDC1: Writeable Keyring         @L4A           
*  $L5=PKIS9    HBB7740 060420 PDRDC1: Writeable Keyring         @L5A           
*  $L6=FIPS     HBB7760 080304 PDXS1:  FIPS support              @L6A           
*  $L7=ME13506  HBB7760 080513 PDXS1:  FIPS support              @L7A           
*  $L8=PKIS12R  HBB7770 090211 PDRDC1: Auto Serial Number        @L8A           
*  $L9=ECC      HBB7770 090505 PDLAW1: ECC support               @L9A           
*  $LA=ECC2     HBB7780 100314 PDSGW1: Hardware ECC              @LAA           
*  $LB=SECTKDS  HBB7790 120203 PDALF1: LI3268.4                  @LBA           
*  $LC=SECTKDS  HBB7790 120203 PDALF1: LI3268.4                  @LCA           
*  $LD=RDATA    HBB77A0 130111 PDALF1: FP0347                    @LDA           
*  $P3=ME26235  HBB77A0 130501 PDALF1: Defect ME26235            @P3A           
*  $LE=RDATA    HBB77A0 130715 PDALF1: FP0347                    @LEA           
*  $LF=CMACROS  HBB77D0 191211 PDM_O1: 352039                    @LFA           
*  $LG=PASSTK4  HBB77D0 200810 PDRDC1: 384055 Enhanced PassTix   @LGA           
*                                                                               
*                                                                               
*01* CHANGE-DESCRIPTIONS:                                                       
*    A000000-999999                                              @L0A           
*  A - Add GSS-API functions                                     @L1A           
*  C - Correct RETNAME parmlist                                  @P1A           
*  A - Add Passticket to GSEC                                    @L2A           
*  C - Corrected pointer declares so PL/X and ASM match          @P2A           
*  A - Add new fspl for writeable keyring support                @L3A           
*      - New functions: NewRing, DataPut, DataRemove, DelRing    @L3A           
*  A - Update R_DataLib for writeable keyring support            @L4A           
*  A - Update R_DataLib for writeable keyring support - Add      @L5A           
*      HIGHTRUST                                                 @L5A           
*  A - Add CDDLX_ATT_SKIPAUTH flag for FIPS support              @L6A           
*  C - Change to limit CDDL_ATT_SKIPAUTH flag for only           @L7A           
*      DataGetFirst, DataGetNext, CheckStatus, GetUpdateCode     @L7A           
*      functions                                                 @L7A           
*  A - Add CDDLX_ATT_SET_MIN_SERIAL for Auto Serial Number       @L8A           
*  A - Support for Elliptic Curve Cryptography                   @L9A           
*  A - Add key type CDDLX_ECC_ICSF                               @LAA           
*  A - Support for Enterprise PKCS#11 Hardware Security          @LBA           
*      - Add CDDLX_RSA_TKDS, CDDLX_ECC_TKDS, and CDDLX_DSA_TKDS  @LBA           
*        key types                                               @LBA           
*  C - Fix PADI assemble errors                                  @LCA           
*  A - SAF program interface to RACDCERT                         @LDA           
*  C - Change pointer declares from 31 bit to 64 bit             @P3A           
*  A - SAF program interface to RACDCERT - Sprint 4              @LEA           
*  A - Many updates to accommodate  CBGENC C-Header generation   @LFA           
*      tool which causes C header files to be built magically    @LFA           
*      during build. Mostly not change flagged because every     @LFA           
*      PLX line is altered or moved.                             @LFA           
*  A - Add R_Gensec PassTicket Generate Extended option          @LGA           
*    - Add R_Gensec PassTicket Evaluate Extended option for      @LGA           
*      this previously provided function                         @LGA           
*                                                                               
*  **Note. When making changes to this part, PLEASE refer to                    
*    the NOTES in the prolog. This part was changed significantly in            
*    z/OS 2.5.                                                                  
*                                                                               
****END OF SPECIFICATIONS*********************************************/         
                                                                                
/*                                                                              
  ********************************************************************          
  ********************************************************************          
  ********************************************************************          
  *                                                                  *          
  *                     COMPX   PL/X DECLARATIONS                    *          
  *------------------------------------------------------------------*          
  *                                                                  *          
  *   DECLARATION NAME = COMPX                                       *          
  *                                                                  *          
  *   DESCRIPTIVE NAME = OMVS common SAF/RACF parameter list.        *          
  *                                                                  *          
  *   FUNCTION = Provides PL/X mapping of the common input parameter *          
  *              list for the   OMVS  SAF/RACF routers.              *          
  *                                                                  *          
  ********************************************************************          
                                                                                
*/                                                                              
struct compx {                     /* Common SAF/RACF plist.                 */ 
  union {                                                                       
    ptr64_t compx_parmcnt_a;       /* Addr of number of parameters           */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_1[4];                                        
      void * __ptr32 compx31_parmcnt_a;                                         
    };                                                                          
  };                                                                            
  union {                                                                       
    ptr64_t compx_worka_stor_a;    /* Addr of 1024 byte work area.           */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_2[4];                                        
      void * __ptr32 compx31_worka_stor_a;                                      
    };                                                                          
  };                                                                            
  union {                                                                       
    ptr64_t compx_safrc_alet_a;    /* Addr of ALET for SAF RC.               */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_3[4];                                        
      void * __ptr32 compx31_safrc_alet_a;                                      
    };                                                                          
  };                                                                            
  union {                                                                       
    ptr64_t compx_safrc_stor_a;    /* Addr of SAF Return Code.               */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_4[4];                                        
      void * __ptr32 compx31_safrc_stor_a;                                      
    };                                                                          
  };                                                                            
  union {                                                                       
    ptr64_t compx_racrc_alet_a;    /* Addr of ALET for RACF Return Code      */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_5[4];                                        
      void * __ptr32 compx31_racrc_alet_a;                                      
    };                                                                          
  };                                                                            
  union {                                                                       
    ptr64_t compx_racrc_stor_a;    /* Addr of RACF Return Code.              */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_6[4];                                        
      void * __ptr32 compx31_racrc_stor_a;                                      
    };                                                                          
  };                                                                            
  union {                                                                       
    ptr64_t compx_racsc_alet_a;    /* Addr of ALET for RACF Reason Code      */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_7[4];                                        
      void * __ptr32 compx31_racsc_alet_a;                                      
    };                                                                          
  };                                                                            
  union {                                                                       
    ptr64_t compx_racsc_stor_a;    /* Addr of RACF Reason Code.              */ 
    struct {                                                                    
      unsigned char irrpcomx_dummy_8[4];                                        
      void * __ptr32 compx31_racsc_stor_a;                                      
/*                                                                              
    Set up magic for C header generation.  If we are not generating a           
     C header, the last part of COMPX is the COMPX_SERVR_PARM char(0)           
     declaration, and everything else is based or defined on                    
     COMPX_SERVR_PARMS.  Each service has a separate mapping declared.          
    If we are generating a                                                      
     C header, the last part of COMPX_SERVR_PARMS is a UNION                    
     declaration, and everything else is declared inside that                   
     UNION, resulting in COMPX being a single, giant UNION of all               
      of the service parameter lists.                                           
                                                                                
*/                                                                              
    };                                                                          
  };                                                                            
  union {                                                                       
    unsigned char compx_servr_parms[48]; /* Service routine parameter lists     
                                   begin here.                               */ 
/*                                                                              
  ********************************************************************          
  *                                                                  *          
  *                CDDLX PL/X DECLARATIONS                           *          
  *------------------------------------------------------------------*          
  *                                                                  *          
  *  DECLARATION NAME = CDDLX                                        *          
  *                                                                  *          
  *  DESCRIPTIVE NAME =   CDSA DataLib Service parameters (64 bit)   *          
  *                                                                  *          
  *  FUNCTION = Provides the ASSEMBLER mapping of the input paramter *          
  *             list for the CDSA Datalib callable service           *          
  ********************************************************************          
                                                                                
*/                                                                              
    unsigned char cddlx[48];       /* Mapping for CDDLX                      */ 
    struct {                                                                    
      ptr64_t cddlx_func_a;        /* Address of 1 byte input function code.    
                                   Constants for the function codes are         
                                   supplied below                            */ 
      ptr64_t cddlx_attributes_a;  /* Address of full word of input attributes  
                                                                             */ 
      ptr64_t cddlx_userid_a;      /* Address of a 9 byte input area for the    
                                   RACF userid (1 byte for the length followed  
                                   by 8 bytes for the RACF userid itself). A    
                                   length of 0 indicates the current user is    
                                   the ring owner                            */ 
      ptr64_t cddlx_ring_a;        /* Address of a variable length input area   
                                   for the ring name (1 byte for the length     
                                   followed by up to 237 bytes for the ring     
                                   name). Parameter ignored for CheckStatus,    
                                   AbortQuery, and DataGetNext               */ 
      ptr64_t cddlx_version_a;     /* Address of a 4 byte area containing the   
                                   input version number for the function        
                                   specific specific parameter list pointed to  
                                   by CDDLX_PARMLIST@. Must be set to 0.     */ 
      ptr64_t cddlx_parmlist_a;    /* Address of the input function specific    
                                   parameter list                            */ 
/*                                                                              
  ********************************************************************          
  *                                                                  *          
  *                GSEC PL/X DECLARATIONS                            *          
  *------------------------------------------------------------------*          
  *                                                                  *          
  *  DECLARATION NAME = GSEC                                         *          
  *                                                                  *          
  *  DESCRIPTIVE NAME =   Kerberos services parameters (64 bit)      *          
  *                                                                  *          
  *  FUNCTION = Provides the ASSEMBLER mapping of the input paramter *          
  *             list for the Kerberos services callable service      *          
  ********************************************************************          
                                                                                
*/                                                                              
    };                                                                          
    unsigned char gsec[32];        /* Mapping GSEC                           */ 
    struct {                                                                    
      union {                                                                   
        ptr64_t gsec_opt_a;        /* Address of option word                 */ 
        struct {                                                                
          unsigned char irrpcomx_dummy_9[4]; /*                              */ 
          void * __ptr32 gsec31_opt_a; /*                                    */ 
        };                                                                      
      };                                                                        
      union {                                                                   
        ptr64_t gsec_func_a;       /* Address of 2 byte input function code.    
                                   Constants for the function codes are         
                                   supplied below                            */ 
        struct {                                                                
          unsigned char irrpcomx_dummy_10[4]; /*                             */ 
          void * __ptr32 gsec31_func_a; /*                                   */ 
        };                                                                      
      };                                                                        
      union {                                                                   
        ptr64_t gsec_func_count_a; /* Address of # of subparms               */ 
        struct {                                                                
          unsigned char irrpcomx_dummy_11[4]; /*                             */ 
          void * __ptr32 gsec31_func_count_a; /*                             */ 
        };                                                                      
      };                                                                        
      union {                                                                   
        ptr64_t gsec_parmlist_a;   /* Address of function specific parameter    
                                   list                                      */ 
        struct {                                                                
          unsigned char irrpcomx_dummy_12[4]; /*                             */ 
          void * __ptr32 gsec31_parmlist_a; /*                               */ 
/*                                                                              
    Add new service here.  Change previous semi-colon to COMPX_Term.            
      End new service declaration with semi-colon.                              
    Put only the main arguments specified on the CALL                           
      statement here.  Constants and other mappings                             
      should be added at the very end of  this macro.                           
  ********************************************************************          
  *                COMPX sub-declares                                *          
  ********************************************************************          
                                                                                
*/                                                                              
#define  COMPX_LEN             112 /* block length                           */ 
/*                                                                              
  ********************************************************************          
  *                CDDLX sub-declares                                *          
  ********************************************************************          
                                                                                
*/                                                                              
#define  CDDLX_LEN             48  /* Constant - length of CDDLX             */ 
        };                                                                      
      };                                                                        
    };                                                                          
  };                                                                            
};                                                                              
                                                                                
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
      Attributes word mapping (pointed to by CDDLX_ATTRIBUTES                   
                                                                                
   ------------------------------------------------------------------           
    This structure contains attribute flags that are applicable to              
    multiple function codes. Do not reuse any of these values in the            
    applicable function-specific mappings below                                 
                                                                                
*/                                                                              
struct cddlx_attributes_map {                                                   
  struct {                                                                      
    uint32_t  : 2;                 /* reserved                               */ 
    uint32_t cddlx_att_skipauth : 1; /* Valid for DataGetFirst, DataGetNext,    
                                   CheckStatus and GetUpdateCode functions OFF: 
                                   Indicate RACF authorization check need to be 
                                   performed ON: Indicate RACF authorization    
                                   will be bypassed for supervisor state or     
                                   system key caller when request is for a RACF 
                                   key ring (not applicable to an ICSF token)   
                                                                             */ 
  };                                                                            
};                                                                              
                                                                                
/*  This struct is defined on cddlx_attributes_map                           */ 
struct cddlx_attr_map_dataget {                                                 
  struct {                                                                      
    uint32_t cddlx_att_all_keytypes : 1; /* Valid only for DataGetFirst and     
                                   DataGetNext - OFF- private key type returned 
                                   will be CDDLX_ICSF (for ICSF or PCICC) or    
                                   CDDLX_PKCS1 (for all others) - ON - private  
                                   key type returned will be CDDLX_ICSF,        
                                   CDDLX_PKCS1, CDDLX_PCICC, CDDLX_DSA,         
                                   CDDLX_DH, CDDLX_ECC, CDDLX_ECC_ICSF,         
                                   CDDLX_RSA_TKDS, CDDLX_ECC_TKDS,              
                                   CDDLX_DSA_TKDS                            */ 
  };                                                                            
};                                                                              
                                                                                
/*  This struct is defined on cddlx_attributes_map                           */ 
struct cddlx_attr_map_newring {                                                 
  struct {                                                                      
    uint32_t cddlx_att_reuse_ring : 1; /* Valid for function NewRing OFF:       
                                   Indicates a new key ring is to be created    
                                   (don't reuse existing ring) ON: Indicates    
                                   that if ring exists, all certs are removed.  
                                                                             */ 
  };                                                                            
};                                                                              
                                                                                
/*  This struct is defined on cddlx_attributes_map                           */ 
struct cddlx_attr_map_dataput {                                                 
  struct {                                                                      
    uint32_t cddlx_att_trust : 1;  /* Valid for DataPut and DataAlter function  
                                   OFF: Indicate RACF will determine status of  
                                   certificate. ON: Indicates that the status   
                                   of the added certificate should be set to    
                                   TRUST                                     */ 
    uint32_t cddlx_att_hightrust : 1; /* Valid for DataPut and DataAlter        
                                   function OFF: Indicate RACF will determine   
                                   status of certificate. ON: Indicates that    
                                   the status of the added certificate should   
                                   be set to HIGHTRUST                       */ 
    uint32_t cddlx_att_notrust : 1; /* Valid for DataPut and DataAlter          
                                   function OFF: Indicate RACF will determine   
                                   status of certificate. ON: Indicates that    
                                   the status of the added certificate should   
                                   be set to NOTRUST                         */ 
  };                                                                            
};                                                                              
                                                                                
/*  This struct is defined on cddlx_attributes_map                           */ 
struct cddlx_attr_map_dataremove {                                              
  struct {                                                                      
    uint32_t cddlx_att_del_cert_too : 1; /* Valid for DataRemove function OFF:  
                                   Indicates the certificate is to be removed   
                                   from the key ring only ON: Indicates the     
                                   certificate is to be deleted from RACF in    
                                   sddition to being removed from the keyring   
                                   as long as it is not connected to any other  
                                   key rings                                 */ 
    uint32_t cddlx_att_del_cert_allrings : 1; /* Valid for DataRemove OFF:      
                                   Indicates the certificate is not to be       
                                   deleted from RACF if it is connected to      
                                   other key rings ON: Indicates the            
                                   certificate is to be deleted from RACF even  
                                   if it is connected to other key rings     */ 
    uint32_t cddlx_att_del_cert_force : 1; /* Valid for DataRemove OFF:         
                                   Indicates the certificate is not to be       
                                   deleted from RACF if has been used to        
                                   generate a request ON: Indicates the         
                                   certificate is to be deleted from RACF even  
                                   if it has been used to generate a request    
                                                                             */ 
  };                                                                            
};                                                                              
                                                                                
/*  This struct is defined on cddlx_attributes_map                           */ 
struct cddlx_attr_map_incserialnum {                                            
  struct {                                                                      
    uint32_t cddlx_att_set_min_serial : 1; /* Valid for IncSerialNum function.  
                                   OFF: Indicate Serial Number is to be         
                                   incremented by one. ON: Indicate the Serial  
                                   number will be incremented to the input      
                                   serial number.                            */ 
  };                                                                            
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
                    Function code constants                                     
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_PARMCNT             14 /* Number of parameters expected       */ 
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
                    Function code constants                                     
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_DATA_GET_FIRST      1 /* DataGetFirst - locate and return the    
                                   first certificate in the ring matching the   
                                   specified criteria                        */ 
#define  CDDLX_DATA_GET_NEXT       2 /* DataGetNext - locate and return the     
                                   next certificate in the ring matching the    
                                   same criteria specified in the previous      
                                   DataGetFirst/DataGetNext call             */ 
#define  CDDLX_DATA_ABORT          3 /* DataAbortQuery - free resources from    
                                   previous DataGetFirst or DataGetNext call    
                                                                             */ 
#define  CDDLX_CHECK_STATUS        4 /* CheckStatus - return the TRUST/NOTRUST  
                                   status for a given certificate            */ 
#define  CDDLX_GET_UPDATE_CODE     5 /* GetUpdateCode - returns the sequence    
                                   number for for a ring                     */ 
#define  CDDLX_INC_SER_NUM         6 /* IncSerialNum - Increments the Serial    
                                   Number for a Digital Certificate          */ 
#define  CDDLX_NEW_RING            7 /* Create a new key ring or remove all     
                                   certificates from an existing key ring    */ 
#define  CDDLX_DATA_PUT            8 /* Add a certificate to RACF and connect   
                                   it to a key ring                          */ 
#define  CDDLX_DATA_REMOVE         9 /* Remove a cert from a key ring and       
                                   optionally delete it from RACF            */ 
#define  CDDLX_DEL_RING            10 /* Delete a key ring                   */ 
#define  CDDLX_DATA_REFRESH        11 /* Refresh the DIGTCERT class.         */ 
#define  CDDLX_DATA_ALTER          12 /* Change the status and/or the label of  
                                   a certificate.                            */ 
#define  CDDLX_GET_RING_INFO       13 /* Return key ring information.        */ 
};                                                                              
                                                                                
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
    Function Specific Parameter Lists                                           
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
struct cddlx_abort {               /* Parameter list for DataAbortQuery      */ 
  ptr64_t cddlx_prev_handle;       /* Address of an input/output area from      
                                   previous DataGetFirst or DataGetNext call    
                                                                             */ 
};                                                                              
                                                                                
struct cddlx_get_cert {            /* Parameter list for DataGetFirst and       
                                   DataGetNext                               */ 
  ptr64_t cddlx_res_handle;        /* Address of input/output area mapped by    
                                   CDDLX_HANDLE_MAP                          */ 
  unsigned char cddlx_cert_usage[4]; /* 4 byte output area containing           
                                   certificate usage flags x'00000000' - Usage  
                                   is SITE x'00000002' - Usage is CERTAUTH      
                                   x'00000008' - Usage is PERSONAL x'FFFFFFF5'  
                                   - reserved bits must be set to zero       */ 
  uint32_t cddlx_cert_default;     /* Output default indicator. Zero value      
                                   indicates not default certificate for ring,  
                                   non-zero indicates this is the default       
                                   certificate.                              */ 
  uint32_t cddlx_cert_len;         /* On input, contains the length of the      
                                   certificate area pointed to by               
                                   CDDLX_CERT_PTR. On output, contains the      
                                   actual size of the certificate returned or 0 
                                   if no certificate returned.               */ 
  int32_t irrpcomx_dummy_13;       /* alignment                              */ 
  ptr64_t cddlx_cert_ptr;          /* Input value specifying address of output  
                                   certificate data area                     */ 
  uint32_t cddlx_pk_len;           /* On input, contains size of private key    
                                   area pointed to by CDDLX_PK_PTR. On output   
                                   contains the length of the private key       
                                   returned at address CDDLX_PK_PTR or 0 if no  
                                   private key was returned                  */ 
  int32_t irrpcomx_dummy_14;       /* alignment                              */ 
  ptr64_t cddlx_pk_ptr;            /* Input value specifying address of private 
                                   key output data area                      */ 
  uint32_t cddlx_pk_type;          /* Output value indicating type of private   
                                   key. See constants below.                 */ 
  uint32_t cddlx_pk_bitsize;       /* Output value indicating the size of the   
                                   private key modulus in bits               */ 
  uint32_t cddlx_label_len;        /* On input, contains the length of the      
                                   field pointed to by CDDLX_LABEL_PTR, and     
                                   must be at least 32. On output, contains the 
                                   length of the label returned at the address  
                                   in CDDLX_LABEL_PTR, and will be 32 or less.  
                                                                             */ 
  int32_t irrpcomx_dummy_15;       /* alignment                              */ 
  ptr64_t cddlx_label_ptr;         /* Input value specifying the address of the 
                                   output area to be used for the label name    
                                                                             */ 
  unsigned char cddlx_racf_userid[9]; /* Input value containing a 1 byte        
                                   length followed by the certificate owning    
                                   userid. The combination of the output label  
                                   and this field uniquely identify a           
                                   certificate                               */ 
  unsigned char irrpcomx_dummy_16[3]; /* Reserved                            */ 
  uint32_t cddlx_sdn_len;          /* On input, contains the length of the      
                                   output buffer pointed to by CDDLX_SDN_PTR.   
                                   On output, contains the length of the BER    
                                   encoded Subject's Distinguished Name         
                                   returned in CDDLX_SDN_LEN.                */ 
  ptr64_t cddlx_sdn_ptr;           /* Input value specifying the address of the 
                                   output area to be used for the Subjects's    
                                   Distinguished Name.                       */ 
  uint32_t cddlx_recid_len;        /* Output value containing the length of the 
                                   record ID returned in area pointed to by     
                                   CDDLX_RECID_PTR, or 0 if no record returned. 
                                                                             */ 
  int32_t irrpcomx_dummy_17;       /* alignment                              */ 
  ptr64_t cddlx_recid_ptr;         /* Input value specifying the address of a   
                                   246 byte area to contain output record ID    
                                   data                                      */ 
  unsigned char cddlx_status[4];   /* Certificate status x'80000000' - TRUST    
                                   x'40000000' - HIGHTRUST x'20000000' -        
                                   NOTRUST x'00000000' - ANY (input only)    */ 
};                                                                              
                                                                                
struct cddlx_crt_status {          /* Parameter list for CheckStatus         */ 
  uint32_t cddlx_crt_len;          /* On input, contains the length of the      
                                   certificate area pointed to by               
                                   CDDLX_CRT_PTR.                            */ 
  int32_t irrpcomx_dummy_18;       /* alignment                              */ 
  ptr64_t cddlx_crt_ptr;           /* Input value specifying address of output  
                                   certificate data area                     */ 
};                                                                              
                                                                                
struct cddlx_get_update {          /* Parm list for GetUpdateCode            */ 
  uint32_t cddlx_ring_seqn;        /* Ring sequence number                   */ 
};                                                                              
                                                                                
struct cddlx_isn {                 /* Parm List for IncSerialNum             */ 
  uint32_t cddlx_isn_clen;         /* Length of DER Encoded input Digital       
                                   Certificate                               */ 
  int32_t irrpcomx_dummy_19;       /* alignment                              */ 
  ptr64_t cddlx_isn_cptr;          /* Address of DER Encoded input Digital      
                                   Certificate                               */ 
  unsigned char cddlx_isn_sernum[8]; /* Output - Incremented Serial Number of   
                                   Digital Certificate                       */ 
};                                                                              
                                                                                
struct cddlx_put_cert {            /* FSPL for DataPut function              */ 
  unsigned char cddlx_pcert_usage[4]; /* 4 byte input area containing           
                                   certificate usage flags x'00000000' - Usage  
                                   is SITE x'00000002' - Usage is CERTAUTH      
                                   x'00000008' - Usage is PERSONAL x'80000000'  
                                   - Usage is defaulted to the usage of the     
                                   cert x'7FFFFFF5' - reserved bits must be set 
                                   to 0                                      */ 
  uint32_t cddlx_pcert_default;    /* Input default cert indicator. Non-zero    
                                   value indicates input certificate is to made 
                                   the default cert for the ring, zero          
                                   indicates to not set the certificate as the  
                                   default                                   */ 
  uint32_t cddlx_pcert_len;        /* Input value containing the length of the  
                                   certificate pointed to by CDDLX_PCERT_PTR.   
                                                                             */ 
  int32_t irrpcomx_dummy_20;       /* reserved for alignment                 */ 
  ptr64_t cddlx_pcert_ptr;         /* Input value specifying address of input   
                                   certificate data area                     */ 
  uint32_t cddlx_pkey_len;         /* Input value containing the size of the    
                                   private key pointed to by the                
                                   CDDLX_PKEY_PTR. A value of zero indicates a  
                                   private key is not being added.           */ 
  int32_t irrpcomx_dummy_21;       /* reserved for alignment                 */ 
  ptr64_t cddlx_pkey_ptr;          /* Input value specifying address of private 
                                   key, ignored if CDDLX_PKEY_LEN value is zero 
                                                                             */ 
  int32_t cddlx_plabel_len;        /* On input, it contains the length of the   
                                   label to be assigned to the added            
                                   certificate. On output, it contains the      
                                   length of the label of the existing          
                                   certificate if the input certificate is      
                                   already installed in RACF.                */ 
  int32_t irrpcomx_dummy_22;       /* reserved for alignment                 */ 
  ptr64_t cddlx_plabel_ptr;        /* On input, it contains the address of the  
                                   label area. On output, it contains the label 
                                   of the existing certificate if the input     
                                   certificate is already installed in RACF.    
                                   The label area must be 32 bytes.          */ 
  unsigned char cddlx_pcert_userid[9]; /* On input, it indicates the owner of   
                                   the certificate, in the format of a 1 byte   
                                   length followed by the user ID. On output it 
                                   contains the owner of the existing           
                                   certificate if the input certificate is      
                                   already installed in RACF. The 1 byte length 
                                   must be 8 and the user ID must be            
                                   left-justified and padded with blanks.    */ 
  unsigned char irrpcomx_dummy_23[3]; /* Reserved space                      */ 
};                                                                              
                                                                                
struct cddlx_remove_cert {         /* FSPL for DataRemove function@L3A       */ 
  uint32_t cddlx_rlabel_len;       /* A 4 byte input value contains the length  
                                   of the label of the certificate to be        
                                   removed pointed to by CDDLX_RLABEL_PTR    */ 
  int32_t irrpcomx_dummy_24;       /* reserved for alignment                 */ 
  ptr64_t cddlx_rlabel_ptr;        /* An input value contains the address of    
                                   the label of the certificate to be removed   
                                                                             */ 
  unsigned char cddlx_rcert_userid[9]; /* A 9 byte input value indicates the    
                                   owner of the certificate to be removed, in   
                                   the format of a 1 byte length followed by    
                                   the user ID. The 1 byte length must be 8 and 
                                   the user ID must be left-justified and       
                                   padded with blanks.                       */ 
  unsigned char irrpcomx_dummy_25[3]; /* Reserved space                      */ 
};                                                                              
                                                                                
struct cddlx_alter_cert {          /* FSPL for DataAlter function            */ 
  uint32_t cddlx_alabel_len;       /* A 4 byte value containing the length of   
                                   the input certificate label.              */ 
  int32_t irrpcomx_dummy_26;       /* reserved for alignment                 */ 
  ptr64_t cddlx_alabel_ptr;        /* A value containing the address of the     
                                   input certificate label.                  */ 
  uint32_t cddlx_anew_label_len;   /* A 4 byte value containing the length of   
                                   the new label which will be assigned to the  
                                   certificate. A zero indicates that the       
                                   change is not on the label.               */ 
  int32_t irrpcomx_dummy_27;       /* reserved for alignment                 */ 
  ptr64_t cddlx_anew_label_ptr;    /* A value containing the address of the new 
                                   certificate label. This field is ignored if  
                                   CDDLX_ANEW_LABEL_LEN is zero.             */ 
  unsigned char cddlx_acert_userid[9]; /* A 9 byte input value indicating the   
                                   owner of the certificate, in the format of a 
                                   1 byte length followed by the user ID. The 1 
                                   byte length must be 8 and the user ID must   
                                   be left-justified and padded with blanks.    
                                   For CERTAUTH certificates, this parameter    
                                   should be set to either 'irrcerta' or        
                                   '*AUTH*'. For SITE certificates, this        
                                   parameter should be set to either 'irrsitec' 
                                   or '*SITE*'. If the length is zero, the      
                                   caller's ID is used.                      */ 
  unsigned char irrpcomx_dummy_28[3]; /* Reserved space                      */ 
};                                                                              
                                                                                
struct cddlx_get_ring {            /* FSPL for GetRingInfo                   */ 
  unsigned char cddlx_ring_srch_type[4]; /* A 4 byte input value which          
                                   identifies more rings to be returned when    
                                   both ring owner and ring name are specified  
                                   x'00000000' - Return just the ring with the  
                                   specified ring owner and ring name           
                                   x'00000001' - Return all rings after the     
                                   ring specified by ring owner and ring name   
                                   x'00000002' - Return all rings with the same 
                                   owner after the ring specified by ring owner 
                                   and ring name x'00000003' - Return all rings 
                                   with the same name after the ring specified  
                                   by ring owner and ring name               */ 
  uint32_t cddlx_ring_res_len;     /* A 4 byte value containing the size of the 
                                   field pointed to by Ring_result_ptr       */ 
  ptr64_t cddlx_ring_res_ptr;      /* An input value containing the address of  
                                   the ring result area                      */ 
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
          Private Key Type Constants returned in CDDLX_PK_TYPE                  
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_PKCS1               1 /* Private key is PKCS#1 DER encoded    */ 
/*                                                                              
   ------------------------------------------------------------------           
    The following constant, CDDLX_PKCS10 should not be used, as                 
    its name is misleading.  It is kept strictly for                            
    compatibility.  Instead use CDDLX_PKCS1.                                    
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_PKCS10              1 /* Private key is PKCS#1 DER encoded    */ 
/*                                                                              
   ------------------------------------------------------------------           
    The following constant, CDDLX_ICSF10 should not be used, as                 
    its name is misleading.  It is kept strictly for                            
    compatibility.  Instead use CDDLX_ICSF.                                     
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_ICSF10              2 /* Private key is a ICSF token          */ 
#define  CDDLX_ICSF                2 /* Alias of private key is a ICSF token    
                                                                             */ 
#define  CDDLX_PCICC               3 /* Private key is a PCICC token label   */ 
#define  CDDLX_DSA                 4 /* Private key is DSA                   */ 
#define  CDDLX_DH                  6 /* Private key is Diffie-Hellman        */ 
#define  CDDLX_ECC                 7 /* Private key is ECC                   */ 
#define  CDDLX_ECC_ICSF            9 /* Private key is ECC PKDS key token    */ 
#define  CDDLX_RSA_TKDS            11 /* Private key is RSA TKDS key token   */ 
#define  CDDLX_ECC_TKDS            13 /* Private key is ECC TKDS key token   */ 
#define  CDDLX_DSA_TKDS            14 /* Private key is DSA TKDS key token   */ 
};                                                                              
                                                                                
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
     Mapping of input/output area pointed to by CDDLX_RES_HANDLE                
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
struct cddlx_handle_map {          /* Mapping of area pointed to by             
                                   CDDLX_RES_HANDLE & CDDLX_PREV_HANDLE      */ 
  void * __ptr32 cddlx_token;      /* Reserved for use by the security server.  
                                   This value must be preserved for subsequent  
                                   calls to DataGetNext and DataAbortQuery   */ 
  uint32_t cddlx_predicates;       /* Input value specifying the selection      
                                   criteria. See constants below             */ 
  uint32_t cddlx_attr_id;          /* Input value specifying the attribute to   
                                   query on. Ignored if CDDLX_PREDICATES is 0.  
                                   See constants below for possible values.  */ 
  uint32_t cddlx_attr_len;         /* Input value containing the length of the  
                                   attributes supplied in CDDLX_ATTR_PTR     */ 
  ptr64_t cddlx_attr_ptr;          /* Input value containing the address of     
                                   query attribute data. Type of data supplied  
                                   determined by CDDLX_ATTR_ID               */ 
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
    Input selection criteria constants supplied in CDDLX_PREDICATES             
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_NONE                0 /* No selection criteria                */ 
#define  CDDLX_ATTR                1 /* Query on a particular attribute      */ 
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
    Input query attributes supplied in CDDLX_ATTR_ID                            
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_LABEL               1 /* The certificate label, up to 32         
                                   characters long                           */ 
#define  CDDLX_DEFAULT             2 /* The default flag, a 4 byte field        
                                   specified as 0 for NO, or a non-zero value   
                                   for YES                                   */ 
#define  CDDLX_SUBJECT             3 /* BER encoded subject's name           */ 
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
    Input selection criteria supplied in CDDLX_RING_SRCH_TYPE                   
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  CDDLX_ONE_RING            0 /* Return just the ring with the specified 
                                   ring owner and ring name                  */ 
#define  CDDLX_ALL_RINGS           1 /* Return all rings after the ring         
                                   specifed by ring owner and ring name      */ 
#define  CDDLX_SAME_OWNER          2 /* Return all rings with the same owner    
                                   after the ring specified by ring owner and   
                                   ring name                                 */ 
#define  CDDLX_SAME_NAME           3 /* Return all rings with the same name     
                                   after the ring specified by ring owner and   
                                   ring name                                 */ 
/*                                                                              
  ********************************************************************          
  *                GSEC  sub-declares                                *          
  ********************************************************************          
                                                                                
*/                                                                              
#define  GSEC_LEN                  32 /* Constant - length of GSEC           */ 
#define  GSEC_PARMCNT              12 /* Number of parameters expected       */ 
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
                    Function code constants                                     
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
#define  GSEC_EXTRACT              1 /* Extract from token                   */ 
#define  GSEC_RETURN_NAME          1 /* ReturnName - Extract principal name     
                                   from token and return it to the invoker   */ 
#define  GSEC_GSSAPI               2 /* Invoke GSS-API service               */ 
#define  GSEC_INIT_SEC_CONTEXT     1 /* Initiate security context            */ 
#define  GSEC_CONT_SEC_CONTEXT     2 /* Continue initiation of security context 
                                                                             */ 
#define  GSEC_ACC_SEC_CONTEXT      3 /* Accept security context              */ 
#define  GSEC_DEL_SEC_CONTEXT      4 /* Delete security context              */ 
#define  GSEC_REL_CRED             5 /* Release credential                   */ 
#define  GSEC_GET_MIC              6 /* Get MIC for message                  */ 
#define  GSEC_VER_MIC              7 /* Verify MIC for message               */ 
#define  GSEC_WRAP_MSG             8 /* Wrap message                         */ 
#define  GSEC_UNWRAP_MSG           9 /* Unwrap message                       */ 
#define  GSEC_EXPORT_SEC_CONTEXT   10 /* Export security context             */ 
#define  GSEC_IMPORT_SEC_CONTEXT   11 /* Import security context             */ 
#define  GSEC_EXPORT_CRED          12 /* Import credential                   */ 
#define  GSEC_IMPORT_CRED          13 /* Export credential                   */ 
#define  GSEC_ACQUIRE_CRED         14 /* Acquire credential                  */ 
#define  GSEC_PASSTICKET           3 /* PassTicket operation                 */ 
#define  GSEC_PASSTICKET_GEN       1 /* PassTicket generate                  */ 
#define  GSEC_PASSTICKET_EVAL      2 /* PassTicket evaluate                  */ 
#define  GSEC_PASSTICKET_EVLX      3 /* PassTicket evaluate extended         */ 
#define  GSEC_PASSTICKET_GENX      4 /* PassTicket generate extended         */ 
};                                                                              
                                                                                
/*                                                                              
   ------------------------------------------------------------------           
                                                                                
    Function Specific Parameter Lists                                           
                                                                                
   ------------------------------------------------------------------           
                                                                                
*/                                                                              
struct gsec_retname {              /* Parameter list for Return name         */ 
  ptr64_t gsec_ret_func_a;         /* Address of function code               */ 
  ptr64_t gsec_ret_cred_len_a;     /* Address of input credential len        */ 
  ptr64_t gsec_ret_input_cred_a;   /* Address of input credential            */ 
  ptr64_t gsec_ret_oid_a;          /* Address of reserved field              */ 
  ptr64_t gsec_ret_ticket_prin_a;  /* Address of area to contain 2           */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * byte length followed by returned                         @L1A !         
      * principal name                                           @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_ret_rc_a;           /* Address of function return code        */ 
};                                                                              
                                                                                
struct gsec31_retname {            /* Parameter list for Return name         */ 
  void * __ptr32 gsec31_ret_func_a;                                             
  void * __ptr32 gsec31_ret_cred_len_a;                                         
  void * __ptr32 gsec31_ret_input_cred_a;                                       
  void * __ptr32 gsec31_ret_oid_a;                                              
  void * __ptr32 gsec31_ret_ticket_prin_a;                                      
  void * __ptr32 gsec31_ret_rc_a;                                               
};                                                                              
                                                                                
struct gsec_gssapi_common {        /* Common parms for GSSAPI functions      */ 
  ptr64_t gsec_gss_func_a;         /* Address of function code word          */ 
  ptr64_t gsec_gss_major_a;        /* Address of area for returned major     */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * status                                                   @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_gss_minor_a;        /* Address of area for returned minor     */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * status                                                   @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_gss_acee_a;         /* Address of ACEE                        */ 
};                                                                              
                                                                                
struct gsec31_gssapi_common {      /* Common parms for GSSAPI functions      */ 
  void * __ptr32 gsec31_gss_func_a;                                             
  void * __ptr32 gsec31_gss_major_a;                                            
  void * __ptr32 gsec31_gss_minor_a;                                            
  void * __ptr32 gsec31_gss_acee_a;                                             
};                                                                              
                                                                                
struct gsec_initseccontext {       /* Parameter list for Initiate            */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * Securty context                                          @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_29[4][8]; /* Common parms                     */ 
  ptr64_t gsec_init_tgt_prin_a;    /* Address of target principal            */ 
  ptr64_t gsec_init_req_flags_a;   /* Address of request flags               */ 
  ptr64_t gsec_init_req_expire_a;  /* Address of requested context expiration   
                                                                             */ 
  ptr64_t gsec_init_cred_hndl_a;   /* Address of credential handle           */ 
  ptr64_t gsec_init_cntxt_hndl_a;  /* Address of returned context handle     */ 
  ptr64_t gsec_init_ret_flags_a;   /* Address of area for return flags       */ 
  ptr64_t gsec_init_cntxt_expire_a; /* Address of area for actual context       
                                   expiration                                */ 
  ptr64_t gsec_init_out_token_a;   /* Address of returned token              */ 
};                                                                              
                                                                                
struct gsec31_initseccontext {     /* Parameter list for Initiate            */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * Securty context                                          @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_30[4][4];                                        
  void * __ptr32 gsec31_init_tgt_prin_a;                                        
  void * __ptr32 gsec31_init_req_flags_a;                                       
  void * __ptr32 gsec31_init_req_expire_a;                                      
  void * __ptr32 gsec31_init_cred_hndl_a;                                       
  void * __ptr32 gsec31_init_cntxt_hndl_a;                                      
  void * __ptr32 gsec31_init_ret_flags_a;                                       
  void * __ptr32 gsec31_init_cntxt_expire_a;                                    
  void * __ptr32 gsec31_init_out_token_a;                                       
};                                                                              
                                                                                
struct gsec_contseccontext {       /* Parameter list for Continue            */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * initiation of security context                           @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_31[4][8]; /* Common parms                     */ 
  ptr64_t gsec_cont_cntxt_hndl_a;  /* Address of context handle              */ 
  ptr64_t gsec_cont_tokln_a;       /* Address of token length                */ 
  ptr64_t gsec_cont_token_a;       /* Address of acceptor context token      */ 
  ptr64_t gsec_cont_ret_flags_a;   /* Address of area for return             */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * flags                                                    @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_cont_expire_a;      /* Address of area for actual             */ 
};                                                                              
                                                                                
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * context expiration                                       @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
struct gsec31_contseccontext {     /* Parameter list for Continue            */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * initiation of security context                           @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_32[4][4];                                        
  void * __ptr32 gsec31_cont_cntxt_hndl_a;                                      
  void * __ptr32 gsec31_cont_tokln_a;                                           
  void * __ptr32 gsec31_cont_token_a;                                           
  void * __ptr32 gsec31_cont_ret_flags_a;                                       
  void * __ptr32 gsec31_cont_expire_a;                                          
};                                                                              
                                                                                
struct gsec_accseccontext {        /* Parameter list for Accept              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_33[4][8]; /* Common parms                     */ 
  ptr64_t gsec_acc_tokln_a;        /* Address of token length                */ 
  ptr64_t gsec_acc_token_a;        /* Address of initiator context           */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * token                                                    @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_acc_contxt_hndl_a;  /* Address of returned context handle     */ 
  ptr64_t gsec_acc_prin_a;         /* Address of area for source             */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * principal                                                @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_acc_ret_flags_a;    /* Address of area for return             */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * flags                                                    @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_acc_cntxt_expire_a; /* Address of area for context expiration    
                                                                             */ 
  ptr64_t gsec_acc_out_token_a;    /* Address of returned token              */ 
  ptr64_t gsec_acc_cred_hndl_a;    /* Address of returned credential         */ 
};                                                                              
                                                                                
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * handle                                                   @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
struct gsec31_accseccontext {      /* Parameter list for Accept              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_34[4][4];                                        
  void * __ptr32 gsec31_acc_tokln_a;                                            
  void * __ptr32 gsec31_acc_token_a;                                            
  void * __ptr32 gsec31_acc_contxt_hndl_a;                                      
  void * __ptr32 gsec31_acc_prin_a;                                             
  void * __ptr32 gsec31_acc_ret_flags_a;                                        
  void * __ptr32 gsec31_acc_cntxt_expire_a;                                     
  void * __ptr32 gsec31_acc_out_token_a;                                        
  void * __ptr32 gsec31_acc_cred_hndl_a;                                        
};                                                                              
                                                                                
struct gsec_delseccontext {        /* Parameter list for Delete              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_35[4][8]; /* Common parms                     */ 
  ptr64_t gsec_del_cntxt_hndl_a;   /* Address of context handle              */ 
};                                                                              
                                                                                
struct gsec31_delseccontext {      /* Parameter list for Delete              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_36[4][4];                                        
  void * __ptr32 gsec31_del_cntxt_hndl_a;                                       
};                                                                              
                                                                                
struct gsec_relcred {              /* Parameter list for Release             */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * credential                                               @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_37[4][8]; /* Common parms                     */ 
  ptr64_t gsec_rel_cred_hndl_a;    /* Address of credential handle           */ 
};                                                                              
                                                                                
struct gsec31_relcred {            /* Parameter list for Release             */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * credential                                               @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_38[4][4];                                        
  void * __ptr32 gsec31_rel_cred_hndl_a;                                        
};                                                                              
                                                                                
struct gsec_getmic {               /* Parameter list for Get MIC for         */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * message                                                  @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_39[4][8]; /* Common parms                     */ 
  ptr64_t gsec_get_contxt_hndl_a;  /* Address of context handle              */ 
  ptr64_t gsec_get_msgln_a;        /* Address of message length              */ 
  ptr64_t gsec_get_msg_a;          /* Address of message                     */ 
  ptr64_t gsec_get_out_tok_a;      /* Address of returned token              */ 
};                                                                              
                                                                                
struct gsec31_getmic {             /* Parameter list for Get MIC for         */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * message                                                  @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_40[4][4];                                        
  void * __ptr32 gsec31_get_contxt_hndl_a;                                      
  void * __ptr32 gsec31_get_msgln_a;                                            
  void * __ptr32 gsec31_get_msg_a;                                              
  void * __ptr32 gsec31_get_out_tok_a;                                          
};                                                                              
                                                                                
struct gsec_vermic {               /* Parameter list for Verify MIC for      */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * message                                                       !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_41[4][8]; /* Common parms                     */ 
  ptr64_t gsec_ver_contxt_hndl_a;  /* Address of context handle              */ 
  ptr64_t gsec_ver_msgln_a;        /* Address of message length              */ 
  ptr64_t gsec_ver_msg_a;          /* Address of message                     */ 
  ptr64_t gsec_ver_tokln_a;        /* Address of length of token             */ 
  ptr64_t gsec_ver_token_a;        /* Address of token                       */ 
};                                                                              
                                                                                
struct gsec31_vermic {             /* Parameter list for Verify MIC for      */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * message                                                       !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_42[4][4];                                        
  void * __ptr32 gsec31_ver_contxt_hndl_a;                                      
  void * __ptr32 gsec31_ver_msgln_a;                                            
  void * __ptr32 gsec31_ver_msg_a;                                              
  void * __ptr32 gsec31_ver_tokln_a;                                            
  void * __ptr32 gsec31_ver_token_a;                                            
};                                                                              
                                                                                
struct gsec_wrapmsg {              /* Parameter list for Wrap a message      */ 
  unsigned char irrpcomx_dummy_43[4][8]; /* Common parms                     */ 
  ptr64_t gsec_wrap_contxt_hndl_a; /* Address of context handle              */ 
  ptr64_t gsec_wrap_req_flag_a;    /* Address of conf-identiality            */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * request flag                                             @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_wrap_msgln_a;       /* Address of message length              */ 
  ptr64_t gsec_wrap_msg_a;         /* Address of message                     */ 
  ptr64_t gsec_wrap_state_a;       /* Address of area for                    */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * conf-identiality state                                   @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_wrap_out_tok_a;     /* Address of returned token              */ 
};                                                                              
                                                                                
struct gsec31_wrapmsg {            /* Parameter list for Wrap a message      */ 
  unsigned char irrpcomx_dummy_44[4][4];                                        
  void * __ptr32 gsec31_wrap_contxt_hndl_a;                                     
  void * __ptr32 gsec31_wrap_req_flag_a;                                        
  void * __ptr32 gsec31_wrap_msgln_a;                                           
  void * __ptr32 gsec31_wrap_msg_a;                                             
  void * __ptr32 gsec31_wrap_state_a;                                           
  void * __ptr32 gsec31_wrap_out_tok_a;                                         
};                                                                              
                                                                                
struct gsec_unwrapmsg {            /* Parameter list for Unwrap a msg        */ 
  unsigned char irrpcomx_dummy_45[4][8]; /* Common parms                     */ 
  ptr64_t gsec_unwrap_contxt_hndl_a; /* Address of context handle            */ 
  ptr64_t gsec_unwrap_tokln_a;     /* Address of token length                */ 
  ptr64_t gsec_unwrap_token_a;     /* Address of token                       */ 
  ptr64_t gsec_unwrap_msg_a;       /* Address of returned message            */ 
  ptr64_t gsec_unwrap_state_a;     /* Address of area for                    */ 
};                                                                              
                                                                                
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * conf-identiality state                                   @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
struct gsec31_unwrapmsg {          /* Parameter list for Unwrap a msg        */ 
  unsigned char irrpcomx_dummy_46[4][4];                                        
  void * __ptr32 gsec31_unwrap_contxt_hndl_a;                                   
  void * __ptr32 gsec31_unwrap_tokln_a;                                         
  void * __ptr32 gsec31_unwrap_token_a;                                         
  void * __ptr32 gsec31_unwrap_msg_a;                                           
  void * __ptr32 gsec31_unwrap_state_a;                                         
};                                                                              
                                                                                
struct gsec_exportseccontext {     /* Parameter list for Export              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_47[4][8]; /* Common parms                     */ 
  ptr64_t gsec_expsec_contxt_hndl_a; /* Address of context handle            */ 
  ptr64_t gsec_expsec_out_tok_a;   /* Address of returned token              */ 
};                                                                              
                                                                                
struct gsec31_exportseccontext {   /* Parameter list for Export              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_48[4][4];                                        
  void * __ptr32 gsec31_expsec_contxt_hndl_a;                                   
  void * __ptr32 gsec31_expsec_out_tok_a;                                       
};                                                                              
                                                                                
struct gsec_importseccontext {     /* Parameter list for Import              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_49[4][8]; /* Common parms                     */ 
  ptr64_t gsec_impsec_tokln_a;     /* Address of length of token             */ 
  ptr64_t gsec_impsec_token_a;     /* Address of token                       */ 
  ptr64_t gsec_impsec_contxt_hndl_a; /* Address of area for context handle   */ 
};                                                                              
                                                                                
struct gsec31_importseccontext {   /* Parameter list for Import              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * security context                                         @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_50[4][4];                                        
  void * __ptr32 gsec31_impsec_tokln_a;                                         
  void * __ptr32 gsec31_impsec_token_a;                                         
  void * __ptr32 gsec31_impsec_contxt_hndl_a;                                   
};                                                                              
                                                                                
struct gsec_exportcred {           /* Parameter list for Export              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * credential                                               @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_51[4][8]; /* Common parms                     */ 
  ptr64_t gsec_expcrd_cred_hndl_a; /* Address of credential handle           */ 
  ptr64_t gsec_expcrd_out_tok_a;   /* Address of returned token              */ 
};                                                                              
                                                                                
struct gsec31_exportcred {         /* Parameter list for Export              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * credential                                               @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_52[4][4];                                        
  void * __ptr32 gsec31_expcrd_cred_hndl_a;                                     
  void * __ptr32 gsec31_expcrd_out_tok_a;                                       
};                                                                              
                                                                                
struct gsec_importcred {           /* Parameter list for Import              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * credential                                               @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_53[4][8]; /* Common parms                     */ 
  ptr64_t gsec_impcrd_tokln_a;     /* Address of length of token             */ 
  ptr64_t gsec_impcrd_token_a;     /* Address of token                       */ 
  ptr64_t gsec_impcrd_cred_hndl_a; /* Address of area for credential handle     
                                                                             */ 
};                                                                              
                                                                                
struct gsec31_importcred {         /* Parameter list for Import              */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * credential                                               @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_54[4][4];                                        
  void * __ptr32 gsec31_impcrd_tokln_a;                                         
  void * __ptr32 gsec31_impcrd_token_a;                                         
  void * __ptr32 gsec31_impcrd_cred_hndl_a;                                     
};                                                                              
                                                                                
struct gsec_acquirecred {          /* Parameter list for Acquire             */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * initiator credential                                     @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_55[4][8]; /* Common parms                     */ 
  ptr64_t gsec_acqcrd_req_expire_a; /* Address of requested credential          
                                   expiraition time                          */ 
  ptr64_t gsec_acqcrd_cred_hndl_a; /* Address of area for credential handle     
                                                                             */ 
  ptr64_t gsec_acqcrd_prin_a;      /* Address of area for principal          */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * name                                                     @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_acqcrd_cred_expire_a; /* Address of area for                  */ 
};                                                                              
                                                                                
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * actual credential expiration time                        @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
struct gsec31_acquirecred {        /* Parameter list for Acquire             */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * initiator credential                                     @L1A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  unsigned char irrpcomx_dummy_56[4][4];                                        
  void * __ptr32 gsec31_acqcrd_req_expire_a;                                    
  void * __ptr32 gsec31_acqcrd_cred_hndl_a;                                     
  void * __ptr32 gsec31_acqcrd_prin_a;                                          
  void * __ptr32 gsec31_acqcrd_cred_expire_a;                                   
};                                                                              
                                                                                
/*                                                                              
    GSEC_FUNC FUNCTION CODE 3                                                   
                                                                                
*/                                                                              
struct gsec_passticket_parms {     /* Parameter list for PassTicket          */ 
  ptr64_t gsec_ticket_options;     /* Address of Passticket option:          */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * 1=generate, 2=evaluate                                   @L2A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_ticket;             /* Address of source or destination       */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * PassTicket                                               @L2A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_userid;             /* Address of Userid for PassTicket       */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * operation                                                @L2A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  ptr64_t gsec_application;        /* Address of PassTicket                  */ 
};                                                                              
                                                                                
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * application ID                                           @L2A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
struct gsec31_passticket_parms {   /* Parameter list for PassTicket          */ 
  void * __ptr32 gsec31_ticket_options; /* Address of Passticket option:     */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * 1=generate, 2=evaluate                                   @L2A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  void * __ptr32 gsec31_ticket;    /* Address of source or destination       */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * PassTicket                                               @L2A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  void * __ptr32 gsec31_userid;    /* Address of Userid for PassTicket       */ 
/*                                                                              
      ****************************************************************!         
      *                                                               !         
      * operation                                                @L2A !         
      *                                                               !         
      ****************************************************************!         
                                                                                
*/                                                                              
  void * __ptr32 gsec31_application; /* Address of PassTicket                */ 
};                                                                              
                                                                                
#pragma pack(pop)                                                               
IHACHDR_PRAGMA_ENABLE_CCN6608                                                   
#endif                                                                          

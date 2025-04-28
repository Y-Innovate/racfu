#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include <stdbool.h>

#include "racfu.h"

// Entry point to the call_racfu() function
static PyObject* call_racfu(PyObject* self, PyObject* args, PyObject* kwargs) {
  PyObject* result_dictionary;
  PyObject* debug_pyobj;
  const char* request_as_string;
  bool debug            = false;

  static char* kwlist[] = {"request", "debug", NULL};

  if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|O", kwlist,
                                   &request_as_string, &debug_pyobj)) {
    return NULL;
  }

  debug                  = PyObject_IsTrue(debug_pyobj);

  racfu_result_t* result = racfu(request_as_string, debug);

  result_dictionary      = Py_BuildValue(
      "{s:y#,s:y#,s:s}", "raw_request", result->raw_request,
      result->raw_request_length, "raw_result", result->raw_result,
      result->raw_result_length, "result_json", result->result_json);

  return result_dictionary;
}

// Method definition
static PyMethodDef _C_methods[] = {
    {"call_racfu", (PyCFunction)call_racfu, METH_VARARGS | METH_KEYWORDS,
     "Python interface to RACF administration APIs"},
    {NULL}
};

// Module definition
static struct PyModuleDef _C_module_def = {
    PyModuleDef_HEAD_INIT, "_C", "Python interface to RACF administration APIs",
    -1, _C_methods};

// Module initialization function
// 'unusedFunction' is a false positive since 'PyInit__C()' is used by the
// Python interpreter
// cppcheck-suppress unusedFunction
PyMODINIT_FUNC PyInit__C(void) {
  Py_Initialize();
  return PyModule_Create(&_C_module_def);
}

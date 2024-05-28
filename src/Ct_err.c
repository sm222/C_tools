#include "../inc/utile.h"

extern const char* const Ct_err_msg[];
extern int Ct_err_code;

/// @brief NOT PROTECTED
/// @param i 
/// @return 
const char*  Ct_strerr(int i) {
  return (Ct_err_msg[i]);
}

//get err code
int    Ct_errErrCode(void) {
  return Ct_err_code;
}


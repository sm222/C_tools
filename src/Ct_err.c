#include "../inc/utile.h"

extern const char* const Ct_err_msg[];
extern int Ct_err_code;

char*  Ct_strerr(int i) {
  return ((char *)Ct_err_msg[i]);
}

int    Ct_errErrCode(void) {
  return Ct_err_code;
}


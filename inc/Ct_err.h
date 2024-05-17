
#ifndef CT_ERR_H
# define CT_ERR_H


int    Ct_errErrCode(void);
char*  Ct_strerr(int i);

# define Ct_ERRCODE       Ct_errErrCode()
# define Ct_ERRMSG(code)  Ct_strerr(code)


#endif // CT_ERR_H

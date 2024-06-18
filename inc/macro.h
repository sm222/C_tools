
#ifndef MACRO_H
# define MACRO_H

#include "C_tool.h"
#include "utile.h"

// time
# define TIME(start, stop, buff_name) tt_time start, stop ; char buff_name[TMP_BUFF_SIZE]; bzero(buff_name, TMP_BUFF_SIZE)
# define TIME_DEF                     TIME(start, stop, buff_name)
# define TIME_START                   TIME_DEF; Ct_start_time(&start)
# define TIME_RESTART                 Ct_start_time(&start); bzero(buff_name, TMP_BUFF_SIZE)
# define TIME_STOP                    Ct_stop_time(&start, &stop, buff_name, TMP_BUFF_SIZE)
//

// log

# define LOG_MSG(str)                  Ct_debug_info("[%C%T%r] %s\n", str)
# define LOG_ERR(str)                  Ct_debug_info("[%R%T%r] %s\n", str)
# define LOG_WAR(str)                  Ct_debug_info("[%Y%T%r] %s\n", str)
//
# define LOG_MSG_F(str, file)          Ct_debug_info("[%C%T%r] %s\n%F", str, (file != NULL ? file : "Ct_log.txt"))
# define LOG_ERR_F(str, file)          Ct_debug_info("[%R%T%r] %s\n%F", str, (file != NULL ? file : "Ct_log.txt"))
# define LOG_WAR_F(str, file)          Ct_debug_info("[%Y%T%r] %s\n%F", str, (file != NULL ? file : "Ct_log.txt"))


// flag
# define FLAG_INIT                     Ct_flag_init()
# define FLAG_ADD(name, cat)           Ct_flag_make(name, cat)
# define FLAG_OUT(cat)                 Ct_flag_print(cat)
# define FLAG_END(bool)                Ct_flag_end(bool)

//trac
# define TRAC_SPEED(val)               Ct_trac_speed(val)
//# define TRAC_ADD(name, val, type)     Ct_trac_add(name, tracChar(val), type)
# define TRAC_ADD_CHAR(name, val)      Ct_trac_add(name, tracChar(val),   _char)
# define TRAC_ADD_INT(name, val)       Ct_trac_add(name, tracInt(val),    _int)
# define TRAC_ADD_FLOAT(name, val)     Ct_trac_add(name, tracFloat(val),  _float)
# define TRAC_ADD_DOUBLE(name, val)    Ct_trac_add(name, tracDouble(val), _double)
# define TRAC_ADD_LINE(name, val)      Ct_trac_add(name, tracLen(val),    _len)
# define TRAC_ADD_PER(name, val)       Ct_trac_add(name, tracPer(val),    _percent)
# define TRAC_RM(name)                 Ct_trac_rm(name)

// err
# define ERR_MSG                       Ct_strerr(Ct_errErrCode())
# define ERR_Code                      Ct_errErrCode()
//

#endif // MACRO_H


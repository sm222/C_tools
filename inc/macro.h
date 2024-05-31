
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

// flag
# define FLAG_INIT                     Ct_flag_init()
# define FLAG_ADD(name, cat)           Ct_flag_make(name, cat)
# define FLAG_OUT(cat)                 Ct_flag_print(cat)
# define FLAG_END(bool)                Ct_flag_end(bool)


// err
# define ERR_MSG         Ct_strerr(Ct_errErrCode())
# define ERR_Code        Ct_errErrCode()
//


#endif // MACRO_H


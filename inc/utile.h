/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:05:37 by anboisve          #+#    #+#             */
/*   Updated: 2024/05/17 14:27:01 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILE_H
# define UTILE_H

# include <strings.h>
# include <string.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include "color.h"

# ifndef CT_CODE
#  define CT_CODE
  extern int	Ct_err_code;
# endif

# define SIZE_BUFF      200
# define BUFF_MUL       2
# define TMP_BUFF_SIZE  30

enum	e_err_msg_code {
  no_err,
  err_malloc,
  didt_call_flag_init,
  can_t_make_flag,
  call_flag_init_more_that_once,
  call_flag_end_with_no_flag,//
  call_flag_print_with_no_flag,
  make_a_flag_with_a_negtive_number,
  call_flag_print_with_no_flag_init,
  print_flag_with_no_init,
  cant_open_file,
  cant_make_file,
  bad_args,
  //
};

enum Dflag {
    DflagBase = 0b00000000,
    DflagOut  = 0b00000001,
    DflagLog  = 0b00000010,
    DflagExit = 0b00000100,
};


typedef struct s_buff {
  ssize_t   len;
  ssize_t   dest;
  char*     str;
  char*     outfile;
}           t_buff;

# ifdef DEBUG_FLAG
#  undef DEBUG_FLAG
# endif
# define DEBUG_FLAG (DflagLog | DflagOut)

# if (DEBUG_FLAG != DflagBase)
#  define DEBUGOUT(msg, va_arg)   debug_info(msg, va_arg)
# else
#  define DEBUGOUT(msg, va_arg)   (void)msg, (void)va_arg
# endif


# ifndef Ct_deff
#  define Ct_deff
#  define Ct_flag 1
#  define Ct_time 2
#  define Ct_mall 3
# endif

int     Ct_strcmp(char* s1, char* s2);
size_t  Ct_str_len(const char* s);
size_t  Ct_put_str(char* s, int fd);
void*   Ct_rt_ptr(void* ptr, int i);

int     Ct_debug(int err, char* file, short clean, char* msg);

char*   ft_ulltoa(unsigned long long nb, int base, char* out);
char*   ft_itoa(int n, char* buff);

int    Ct_errErrCode(void);


typedef struct s_flag {
  char*           name;
  size_t          time;
  short           cat;
  struct s_flag*  next;
} Ct_t_flag;

#endif

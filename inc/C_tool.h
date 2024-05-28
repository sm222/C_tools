/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_tool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:39:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:33 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_TOOL_H
# define C_TOOL_H

# include "color.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "Ct_err.h"
# include "macro.h"
# define  LINE "__________________________________"

typedef struct timeval tt_time;



# define MEM_OUT_FILE	".mem_file"


// flag

int         Ct_flag_init(void);
int         Ct_flag_make(char* name, short cat);
int         Ct_flag_print(short cat);
int         Ct_flag_end(short print);

// time

char*       Ct_time_return(void);
void        Ct_time_print(void);

//

void        Ct_err(char* msg);
int         Ct_strcmp(char* s1, char* s2);
void        Ct_mprintf(void* ptr, size_t size, int type, int name);
void        Ct_memcmp_print(void* ptr1, void* ptr2, size_t size, int type);

// log
ssize_t     Ct_debug_info(const char* s, ...);
int         Ct_debug_pro(int err, char* file, short clean, char* msg, ...);

//time 
short       Ct_start_time(tt_time* start);
const char* Ct_stop_time(tt_time* start, tt_time* stop, char* out, int size);

//malloc

//

typedef struct s_tool {
  int     i;
  int     j;
  size_t  x;
  size_t  y;
  char*   s;
  char*   str;
} t_tool;


#endif

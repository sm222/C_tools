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

# include "Ct_lib/Ctlib.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "color.h"
# include <stdlib.h>
# include <errno.h>

# define LINE "__________________________________"

int	err_code;
# define MEM_OUT_FILE	".mem_file"


enum	e_err_msg_code {
	no_err,
	err_malloc,
	didt_call_flag_init,
	can_t_make_flag,
	call_flag_init_more_that_once,
	call_flag_end_with_no_flag,
	call_flag_print_with_no_flag,
	make_a_flag_with_a_negtive_number,
	call_flag_print_with_no_flag_init,
	cant_open_file,
	bad_args,
};

// flag

int		Ct_flag_init(void);
int		Ct_make_flag(char *name, short cat);
int		Ct_flag_print(short cat);
int		Ct_flag_end(short print);

// time

char	*Ct_time_return(void);
void	Ct_time_print(void);

//

void	Ct_err(char *msg);
int		Ct_strcmp(char *s1, char *s2);
void	Ct_mprintf(void *ptr, size_t size, int type, int name);
void	Ct_memcmp_print(void *ptr1, void *ptr2, size_t size, int type);

// log
int		Ct_debug(int err, char *file, short clean, char *msg);
int		Ct_debug_pro(int err, char *file, short clean, char *msg, ...);

//malloc
void	*Ct_malloc(size_t size);
void	Ct_mall_track(void *ptr);

typedef struct s_tool {
	int		i;
	int		j;
	size_t	x;
	size_t	y;
	char	*s;
	char	*str;

}	t_tool;

typedef struct s_flag {
	char			*name;
	size_t			time;
	short			cat;
	struct s_flag	*next;
}	Ct_t_flag;

#endif

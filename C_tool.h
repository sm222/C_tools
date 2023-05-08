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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "color.h"
# include <stdlib.h>
# include <errno.h>

# ifndef ERR_CODE
#  define ERR_CODE
int			err_code;
# endif

char	*Ct_strdup(char *s1);
int		flag_end(void);
int		flag_init(void);
void	Ct_err(char *msg);
int		make_flag(char *name);
void	*Ct_rt_ptr(void *ptr, int i);
void	Ct_mprintf(void *ptr, size_t size, int type, int name);
void	Ct_memcmp(void *ptr1, void *ptr2, size_t size, int type);
int		pass_flag(char *ft, int mode);
int		Ct_strcmp(char *s1, char *s2);

typedef struct s_tool {
	int		i;
	int		j;
	size_t	x;
	size_t	y;
	char	*s;
	char	*str;

}	t_tool;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 90
# endif
typedef struct s_flag {
	char			*name;
	size_t			time;
	struct s_flag	*next;
}	t_flag;

#endif

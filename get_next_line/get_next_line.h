/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:32:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/08 13:03:01 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../C_tool.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_info
{
	char	*tmp;
	char	*tmp2;
	int		rv;
	size_t	cut;
}	t_info;

void	*Ct_sfree(void *p);
void	*Ct_calloc(size_t size, size_t count);
char	*get_next_line(int fd);
void	Ct_bzero(void *p, size_t size);

#endif // GET_NEXT_LINE_H

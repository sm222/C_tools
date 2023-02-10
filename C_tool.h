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

void	Ct_mprintf(void *ptr, size_t size, int type, int name);
void	Ct_memcmp(void *ptr1, void *ptr2, size_t size, int type);

typedef struct s_tool {
	int		i;
	int		j;
	size_t	x;
	size_t	y;
	char	*s;
	char	*str;

} t_tool;



#endif
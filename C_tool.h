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

void	Ct_mprintf(void *ptr, size_t size, int type);
void	Ct_memcmp(void *ptr1, void *ptr2, size_t size, int type);

typedef struct s_tool {
	int		bonjour;
	char	lettre;
	size_t	index;

} t_tool;



#endif
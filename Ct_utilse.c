/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_utilse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:10:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/07 11:30:14 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"

static size_t	Ct_len(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	Ct_err(char *msg)
{
	write(2, msg, Ct_len(msg));
	write(2, " : ", 3);
	write(2, Ct_err_msg[Ct_err_c], Ct_len(Ct_err_msg[Ct_err_c]));
	write(2, "\n", 1);
}

void	*Ct_rt_ptr(void *ptr, int i)
{
	static void	*list[100];

	if (ptr && i > 0 && i < 101)
		list[i] = ptr;
	if (!ptr && i > 0 && i < 101)
		return (list[i]);
	return (NULL);
} 

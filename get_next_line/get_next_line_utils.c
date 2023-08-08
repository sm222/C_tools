/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:31:55 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/08 13:01:48 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	Ct_bzero(void *p, size_t size)
{
	while (size--)
		((char *)p)[size] = 0;
}

void	*Ct_sfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

void	*Ct_calloc(size_t size, size_t count)
{
	char	*new;

	new = malloc(size * count);
	if (!new)
		return (new = Ct_sfree(new));
	Ct_bzero(new, size * count);
	return (new);
}



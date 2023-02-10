/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_mprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:37:45 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/09 18:37:45 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"

void	Ct_mprintf(void *ptr, size_t size, int type)
{
	size_t	i;

	i = 0;
	if (type == 0)
	{
		while (i < size)
			printf("%12d | ", ((char *)ptr)[i++]);
	}
	else if (type == 1)
	{
		while (i < size)
			printf("%2c | ", ((char *)ptr)[i++]);
	}
	printf("\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:57:31 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/09 18:57:31 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"

void	Ct_memcmp(void *ptr1, void *ptr2, size_t size, int type)
{
	size_t	i;

	i = 0;
	Ct_mprintf(ptr1, size, type, 'A');
	if (type == 0)
	{
		printf("[i]");
		while (i < size)
			printf("%12ld | ", i++);
	}
	else if (type == 1)
	{
		printf("[i]");
		while (i < size)
			printf("%3ld | ", i++);
	}
	printf("\n");
	Ct_mprintf(ptr2, size, type, 'B');
}
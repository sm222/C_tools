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

/// @brief use to comper 2 array of memorry
/// @param ptr1 ptr1
/// @param ptr2 ptr2
/// @param size size of the array compere
/// @param type 1 char, 0 int
void	Ct_memcmp_print(void *ptr1, void *ptr2, size_t size, int type)
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
		printf(YEL);
		printf("[i]");
		while (i < size)
			printf("%3ld | ", i++);
		printf(WHT);
	}
	printf("\n");
	Ct_mprintf(ptr2, size, type, 'B');
}

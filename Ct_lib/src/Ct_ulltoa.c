/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:00:16 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:33:50 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_printf.h"

static int	Ct_size_of_unb(unsigned long long nb, int base)
{
	int	size;

	size = 0;
	while (nb)
	{
		size++;
		nb /= base;
	}
	return (size);
}

/*
take a number and a base and return a malloc str
*/
char	*Ct_ulltoa(unsigned long long nb, int base)
{
	char		*result;
	int			i;

	i = Ct_size_of_unb(nb, base);
	if (nb == 0)
		i++;
	result = Ct_calloc(i + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (i--)
	{
		result[i] = HEX_TABLE[nb % base];
		nb /= base;
	}
	return (result);
}

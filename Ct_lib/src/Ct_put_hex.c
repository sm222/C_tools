/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:51:22 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:32:25 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_printf.h"

/*
put number in hex
if maj = X, it will output in maj
*/
int	Ct_put_hex(unsigned int nb, char maj, int fd)
{
	int		size;
	char	*tmp;

	tmp = Ct_ulltoa(nb, 16);
	size = Ct_strlen(tmp) + 1;
	if (maj == 'X')
		while (size--)
			tmp[size] = Ct_toupper(tmp[size]);
	size = Ct_putstr_fd(tmp, fd);
	Ct_free(tmp);
	return (size);
}

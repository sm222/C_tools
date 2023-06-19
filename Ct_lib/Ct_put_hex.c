/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:51:22 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ct_printf.h"

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

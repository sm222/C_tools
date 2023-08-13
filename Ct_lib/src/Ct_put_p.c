/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:09:21 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:32:29 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_printf.h"

/*
print a adress like printf
*/
int	Ct_put_p(unsigned long p, int fd)
{
	char	*tmp;
	int		size;

	size = Ct_putstr_fd("0x", fd);
	tmp = Ct_ulltoa((unsigned long)p, 16);
	size += Ct_putstr_fd(tmp, fd);
	if (tmp)
		Ct_free(tmp);
	return (size);
}

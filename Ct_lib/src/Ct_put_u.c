/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:01:10 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:32:31 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_printf.h"

/*
print unsigned int
*/
int	Ct_put_u(unsigned int nb, int fd)
{
	int		size;
	char	*tmp;

	tmp = Ct_ulltoa(nb, 10);
	size = Ct_putstr_fd(tmp, fd);
	Ct_free(tmp);
	return (size);
}

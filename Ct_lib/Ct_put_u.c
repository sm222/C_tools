/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:01:10 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:48:10 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ct_printf.h"

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

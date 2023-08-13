/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:10:25 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

static int	size_int(int long nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 9)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

int	Ct_putnbr_fd(int n, int fd)
{
	int	size;

	size = size_int(n);
	if (n == -2147483648)
		Ct_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		Ct_putchar_fd('-', fd);
		Ct_putnbr_fd(n * -1, fd);
	}
	else if (n > 9)
	{
		Ct_putnbr_fd(n / 10, fd);
		Ct_putchar_fd(n % 10 + '0', fd);
	}
	else
		Ct_putchar_fd(n + '0', fd);
	return (size);
}

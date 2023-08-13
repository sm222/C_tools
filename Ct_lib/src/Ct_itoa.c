/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:25:48 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

static int	num_s(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{	
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	set_str(char *s, int i, int long n)
{
	if (i > 0)
	{
		s[i] = n % 10 + '0';
		set_str(s, i - 1, n / 10);
	}
	else
		s[i] = n % 10 + '0';
}

/// @brief take a int and return a char *
/// @param n number
/// @return number in text
char	*Ct_itoa(int n)
{
	char		*new;
	long int	temp;

	temp = n;
	new = Ct_calloc(num_s(n) + 1, sizeof(char));
	if (!new)
		return (NULL);
	else if (temp < 0)
		temp = temp * -1;
	set_str(new, num_s(n) - 1, temp);
	if (n < 0)
		new[0] = '-';
	return (new);
}

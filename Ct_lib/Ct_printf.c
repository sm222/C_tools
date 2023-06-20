/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:12:13 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 22:11:16 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ct_printf.h"

static int	print_free(char *s, char c, int fd)
{
	int	len;

	len = Ct_strlen(s);
	write(fd, s, len);
	if (c == 'S')
		free(s);
	return (len);
}

static int	Ct_print_select(va_list list, char c, int fd)
{
	char	*s;

	if (c == 's' || c == 'S')
	{
		s = va_arg(list, char *);
		if (!s)
			return (Ct_putstr_fd("(null)", fd));
		return (print_free(s, c, fd));
	}
	else if (c == 'i' || c == 'd')
		return (Ct_putnbr_fd(va_arg(list, int), fd));
	else if (c == 'c')
		return (Ct_putchar_fd(va_arg(list, int), fd));
	else if (c == 'p')
		return (Ct_put_p(va_arg(list, unsigned long), fd));
	else if (c == '%')
		return (Ct_putchar_fd('%', fd));
	else if (c == 'x' || c == 'X')
		return (Ct_put_hex(va_arg(list, unsigned int), c, fd));
	else if (c == 'u')
		return (Ct_put_u(va_arg(list, unsigned int), fd));
	return (0);
}

static int	make_new_str(char *s, va_list arg, char **out)
{
	*out = NULL;
	*out = Ct_combine(s + 2, arg);
	return (Ct_strlen(*out));
}

/// @brief use to print like printf, "%o" give a adresse of a char *
/// @brief make a news string like a printf and return it
/// @param fd chose output
/// @details s = str 
/// @details S = str but will free it for you
/// @details d || i for int
/// @details x = hexadecimal
/// @details %% = add one %
/// @return len
int	Ct_printf(int fd, char *str, ...)
{
	Ct_t_printf	pf;

	Ct_bzero(&pf, sizeof(Ct_t_printf));
	if (!str)
		return (0);
	va_start(pf.arg, str);
	if (Ct_strncmp(str, "%o", 2) == 0)
		return (make_new_str(str, pf.arg, va_arg(pf.arg, char **)));
	while (str[pf.i])
	{
		if (str[pf.i] != '%')
			pf.total += Ct_putchar_fd(str[pf.i], fd);
		else
		{
			if (str[++pf.i] == 0)
				continue ;
			pf.total += Ct_print_select(pf.arg, str[pf.i], fd);
		}
		pf.i++;
	}
	va_end(pf.arg);
	return (pf.total);
}

/*
Ct_printf.c
Ct_put_hex.c
Ct_put_p.c
Ct_put_u.c

Ct_ulltoa.c
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:13:03 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 16:39:48 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CT_PRINTF_H
# define CT_PRINTF_H

# include "Ct_lib.h"

# ifndef NO_PRINT
#  define NO_PRINT -1
# endif

typedef struct Cs_printf
{
	va_list	arg;
	size_t	i;
	int		total;
	char	**out;
}	Ct_t_printf;

int		Ct_printf(int fd, char *str, ...);
int		Ct_put_p(unsigned long p, int fd);
char	*Ct_ulltoa(unsigned long long nb, int base);
int		Ct_put_hex(unsigned int nb, char maj, int fd);
int		Ct_put_u(unsigned int nb, int fd);

#endif

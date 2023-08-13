/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:13:03 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:48 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CT_PRINTF_H
# define CT_PRINTF_H

# include "Ct_lib.h"

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

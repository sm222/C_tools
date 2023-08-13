/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:32:07 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/// @brief look in a str for a char
/// @param s str
/// @param c target
/// @return adress of the targer
char	*Ct_strchr(const char *s, int c)
{
	size_t		i;
	size_t		n;

	if (!s)
		return (NULL);
	i = 0;
	n = Ct_strlen(s);
	while (i <= n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	return (NULL);
}

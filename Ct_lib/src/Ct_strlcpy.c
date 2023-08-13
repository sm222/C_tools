/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:18:25 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/// @brief 
/// @param dst 
/// @param src 
/// @param dstsize 
/// @return 
size_t	Ct_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s;

	if (!dst || !src)
		return (0);
	s = Ct_strlen(src);
	if (s + 1 < dstsize)
		Ct_memcpy(dst, ((char *)src), s + 1);
	else if (dstsize != 0)
	{
		Ct_memcpy(dst, ((char *)src), dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (s);
}

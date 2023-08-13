/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:34:32 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/// @brief why you want to use that ?!
/// @return 
size_t	Ct_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;

	if (!dst || !src)
		return (0);
	d = Ct_strlen(dst);
	if (dstsize <= d)
		return (dstsize + Ct_strlen(src));
	dstsize -= d + 1;
	while (dstsize-- > 0 && *src)
		dst[d++] = *src++;
	dst[d] = '\0';
	return (Ct_strlen(src) + d);
}

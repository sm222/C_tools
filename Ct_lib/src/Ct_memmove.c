/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:46:35 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:48 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/// @brief move memorry form src to dest
/// @param dst 
/// @param src 
/// @param len memory len in byte
/// @return adress of dest
void	*Ct_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL || src == NULL)
		return (NULL);
	if (src < dst)
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	else
		Ct_memcpy(dst, src, len);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:48:51 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:48 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/// @brief put all the memory to zero the size of n
/// @param s input
/// @param n size of byte
void	Ct_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	while (n--)
		((char *)s)[n] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:50:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:48 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/// @brief free a pointer if the adrres in not NULL
/// @param p input
/// @return NULL
void	*Ct_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

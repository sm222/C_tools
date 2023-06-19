/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:50:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:46:22 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ctlib.h"

/// @brief free a pointer if the adrres in not NULL
/// @param p input
/// @return NULL
void	*Ct_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

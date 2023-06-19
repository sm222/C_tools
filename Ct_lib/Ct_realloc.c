/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:46:45 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ctlib.h"

/*
realloc give you the size of the memory you want on the same poiter
*/
void	*Ct_realloc(void *old, size_t count, size_t len, size_t new_len)
{
	void	*new;

	if (!old)
		return (NULL);
	new = Ct_calloc(count, new_len);
	if (!new)
		return (NULL);
	if (len <= new_len)
		Ct_memcpy(new, old, count * len);
	else
		Ct_memcpy(new, old, count * new_len);
	Ct_free(old);
	return (new);
}

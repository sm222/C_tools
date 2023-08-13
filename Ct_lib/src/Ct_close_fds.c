/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_close_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:13:41 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/*
use to close file descriptors.
open by pipe on a 2D array.
if f_prt = 1 the 2D array will be free
*/

/// @brief use to close file descriptors open by pipe on a 2D array.
/// @param fds double array of pointer 
/// @param f_ptr flag to free or not the double array if it is true
/// @return number of fd close
int	Ct_close_fds(int **fds, int f_ptr, int size)
{
	int	i;
	int	close_nb;

	i = 0;
	close_nb = 0;
	while (size--)
	{
		if (close(fds[i][0]) == 0)
			close_nb++;
		if (close(fds[i][1]) == 0)
			close_nb++;
		if (f_ptr)
			fds[i] = Ct_free(fds[i]);
		i++;
	}
	if (f_ptr && fds)
		fds = Ct_free(fds);
	return (close_nb);
}

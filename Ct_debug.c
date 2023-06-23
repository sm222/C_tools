/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:37:39 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/23 13:08:23 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"

int	Ct_debug_pro(int err, char *file, short clean, char *msg, ...)
{
	va_list	list;
	char	*out;

	if (!msg)
		return (bad_args * -1);
	va_start(list, msg);
	out = Ct_combine(msg, list);
	Ct_debug(err, file, clean, out);
	Ct_free(out);
	return (1);
}

/// @brief use to print a err code in a ouput file
/// @param err err the ft return and print
/// @param msg msg to print in the file
/// @param file file name and path
/// @return err code to put in the return ft
int	Ct_debug(int err, char *file, short clean, char *msg)
{
	int		fd;
	char	*t;
	int		flag = O_APPEND;

	if (clean)
		flag = O_TRUNC;
	fd = open(file, O_CREAT | flag | O_RDWR, 0644);
	if (fd == -1)
	{
		err_code = can_t_make_flag;
		Ct_putstr_fd("can't, make debug file\n", 2);
		return (cant_open_file * -1);
	}
	Ct_printf(-1, "%o%d %s\n", &t, err ,msg);
	if (!t)
		err_code = err_malloc;
	else
		Ct_putstr_fd(t, fd);
	Ct_free(t);
	close(fd);
	return (err);
}
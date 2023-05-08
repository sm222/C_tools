/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:06:59 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/07 23:05:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"

extern int	err_code;

size_t	flag_len(t_flag *in)
{
	size_t	i;

	i = 0;
	while (in)
	{
		in = in->next;
		i++;
	}
	return (i);
}

static t_flag	*make_node_flag(char *name)
{
	t_flag	*new;

	new = calloc(1, sizeof(t_flag));
	if (!new)
	{
		err_code = 1;
		return (NULL);
	}
	new->name = Ct_strdup(name);
	new->time = 1;
	new->next = NULL;
	return (new);
}

/// @brief make a flag with the name you call it,
/// @brief if you call the same flag it will got up by one
/// @param name name of the flag
/// @return 0 if flag_init was not call fist,
/// @return -1 malloc fail,
int	Ct_make_flag(char *name)
{
	t_flag	**tmp;
	t_flag	*tm;

	tmp = Ct_rt_ptr(NULL, 1);
	if (tmp == NULL)
		return (err_code = 2, 0);
	if (*tmp == NULL)
	{
		*tmp = make_node_flag(name);
		if (!*tmp)
			return (err_code = 1, -1);
	}
	else
	{
		tm = (*tmp);
		while (tm)
		{
			if (Ct_strcmp(tm->name, name) == 0)
			{
				tm->time++;
				return (tm->time);
			}
			tm = tm->next;
		}
		tm = (*tmp);
		while (tm->next)
			tm = tm->next;
		tm->next = make_node_flag(name);
		if (!tm->next)
			return (err_code = 2, -1);
	}
	return (1);
}

/// @brief start the flag variable
/// @return return 1 if do once, return -1 if call more that once
int	Ct_flag_init(void)
{
	static t_flag	*f_list = NULL;

	if (f_list)
	{
		err_code = 4;
		return (-1);
	}
	else
		Ct_rt_ptr(&f_list, 1);
	return (1);
}

/// @brief call at the end of your program after you use all the flag
/// @return return -1 if falure, 1 if sucsesse
int	Ct_flag_end(void)
{
	t_flag	**d;
	t_flag	*end;
	t_flag	*tmp;

	d = Ct_rt_ptr(NULL, 1);
	if (!d)
		return (err_code = 5, -1);
	end = (*d);
	while (end)
	{
		printf("%10s/%5zu\n", end->name, end->time);
		free(end->name);
		tmp = end->next;
		free(end);
		end = tmp;
	}
	Ct_rt_ptr(NULL, -1);
	return (1);
}
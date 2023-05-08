/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:06:59 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/08 12:39:28 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"
#include "utile.h"

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

static t_flag	*make_node_flag(char *name, short cat)
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
	new->cat = cat;
	new->next = NULL;
	return (new);
}

/// @brief make a flag with the name you call it,
/// @brief if you call the same flag it will got up by one
/// @param name name of the flag
/// @return 0 if flag_init was not call fist,
/// @return -1 malloc fail,
int	Ct_make_flag(char *name, short cat)
{
	t_flag	**tmp;
	t_flag	*tm;

	tmp = Ct_rt_ptr(NULL, Ct_flag);
	if (tmp == NULL)
		return (err_code = 2, 0);
	if (cat < 0)
		return (err_code = 7, 0);
	if (*tmp == NULL)
	{
		*tmp = make_node_flag(name, cat);
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
			if (!tm->next)
				break ;
			tm = tm->next;
		}
		tm->next = make_node_flag(name, cat);
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
		Ct_rt_ptr(&f_list, Ct_flag);
	return (1);
}

/// @brief use to print to flag on screan
/// @param cat wich catego you want to show, number under 0 show them all
/// @return return -1 if call with no flag, else return 1
int	Ct_flag_print(short cat)
{
	t_flag	**d;
	t_flag	*tmp;

	d = Ct_rt_ptr(NULL, Ct_flag);
	if (!d)
		return (err_code = call_flag_print_with_no_flag_init, -1);
	tmp = (*d);
	if (tmp)
	{
		printf("%10s | %9s | %3s\n", "Name", "time call", "cat");
		printf("%s\n", "____________________________");
	}
	else
		return (err_code = call_flag_print_with_no_flag, -1);
	while (tmp)
	{
		if (tmp->cat == cat || cat < 0)
			printf("%10.10s | %9zu | %3d\n", tmp->name, tmp->time, tmp->cat);
		tmp = tmp->next;
	}
	printf("%s\n", "____________________________");
	return (1);
}


/// @brief call at the end of your program after you use all the flag
/// @param print print the result at the end or not
/// @return return -1 if falure, 1 if sucsesse
int	Ct_flag_end(short print)
{
	t_flag	**d;
	t_flag	*end;
	t_flag	*tmp;

	d = Ct_rt_ptr(NULL, Ct_flag);
	if (!d)
		return (err_code = call_flag_end_with_no_flag, -1);
	end = (*d);
	if (end)
	{
		if (print > 0)
		{
			printf("%10s | %9s | %3s\n", "Name", "time call", "cat");
			printf("%s\n", "____________________________");
		}
	}
	else
	{
		Ct_rt_ptr(NULL, Ct_flag * -1);
		return (err_code = call_flag_end_with_no_flag, -1);
	}
	while (end)
	{
		if (print > 0)
			printf("%10.10s | %9zu | %3d\n", end->name, end->time, end->cat);
		free(end->name);
		tmp = end->next;
		free(end);
		end = tmp;
	}
	if (print > 0)
		printf("%s\n", "____________________________");
	Ct_rt_ptr(NULL, Ct_flag * -1);
	return (1);
}
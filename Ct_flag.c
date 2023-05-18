/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:06:59 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/17 20:48:52 by anboisve         ###   ########.fr       */
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
	t_flag	*new = NULL;

	new = calloc(1, sizeof(t_flag));
	if (!new)
	{
		err_code = 1;
		return (NULL);
	}
	new->name = Ct_strdup(name);
	if (!new->name)
	{
		free(new);
		err_code = 1;
		return (NULL);
	}
	new->time = 1;
	new->cat = cat;
	new->next = NULL;
	return (new);
}

/// @brief make a flag with the name you call it,
/// @brief if you call the same flag it will got up by one
/// @param name name of the flag
/// @return 0 if flag_init was not call fist,
/// @return -1 malloc fail, 1 on success
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
			if (Ct_strcmp(tm->name, name) == 0 && tm->cat == cat)
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
/// @return return 1 if do once, return 0 if call more that once
int	Ct_flag_init(void)
{
	static t_flag	*f_list = NULL;

	if (f_list)
	{
		err_code = 4;
		return (0);
	}
	else
		Ct_rt_ptr(&f_list, Ct_flag);
	return (1);
}

/// @brief use to print to flag on screan
/// @param cat wich catego you want to show, number under 0 show them all
/// @return return 0 if call with no flag, else return 1
int	Ct_flag_print(short cat)
{
	t_flag	**d;
	t_flag	*tmp;
	size_t	total = 0;

	d = Ct_rt_ptr(NULL, Ct_flag);
	if (!d)
		return (err_code = call_flag_print_with_no_flag_init, 0);
	tmp = (*d);
	if (tmp)
	{
		printf(" %3s %11.11s %15.15s\n", "cat", "time call", "name");
		printf("%s\n", LINE);
	}
	else
		return (err_code = call_flag_print_with_no_flag, 0);
	while (tmp)
	{
		if (tmp->cat == cat || cat < 0)
		{
			printf("%3d | %11zu| %15.15s\n", tmp->cat, tmp->time, tmp->name);
			total += tmp->time;
		}
		tmp = tmp->next;
	}
	printf("%s\n", LINE);
	printf("%zu %13.13s\n",total , "total");
	return (1);
}


/// @brief call at the end of your program after you use all the flag
/// @param print print the result at the end or not
/// @return return 0 if falure, 1 if sucsesse
int	Ct_flag_end(short print)
{
	t_flag	**d;
	t_flag	*end;
	t_flag	*tmp;

	d = Ct_rt_ptr(NULL, Ct_flag);
	if (!d)
		return (err_code = call_flag_end_with_no_flag, 0);
	end = (*d);
	if (end)
	{
		if (print > 0)
			Ct_flag_print(-1);
		while (end)
		{
			free(end->name);
			tmp = end->next;
			free(end);
			end = tmp;
		}
		Ct_rt_ptr(NULL, Ct_flag * -1);
		return (1);
	}
	Ct_rt_ptr(NULL, Ct_flag * -1);
	return (err_code = call_flag_end_with_no_flag, 0);
}
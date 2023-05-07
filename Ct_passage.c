/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_passage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:06:59 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/07 17:10:43 by anboisve         ###   ########.fr       */
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

int	make_flag(char *name)
{
	t_flag	**tmp;
	t_flag	*tm;
	size_t	i;

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
		i = flag_len(*tmp);
		tm = (*tmp);
		while (--i)
		{
			if (Ct_strcmp(tm->name, name) == 0)
			{
				tm->time++;
				return (tm->time);
			}
			tm = tm->next;
		}
		tm->next = make_node_flag(name);
		if (!tm->next)
			return (err_code = 2, 0);
	}
	return (1);
}

int	flag_init(void)
{
	static t_flag	*f_list = NULL;

	Ct_rt_ptr(&f_list, 1);
	return (1);
}

int	pass_flag(char *ft, int mode)
{
	(void)ft;
	(void)mode;
	return (1);
}

int	flag_end(void)
{
	t_flag	**d;
	t_flag	*end;
	t_flag	*tmp;

	d = Ct_rt_ptr(NULL, 1);
	if (!d)
		return (err_code = 2,  -1);
	end = (*d);
	while (end)
	{
		printf("%s = %zu\n", end->name, end->time);
		tmp = end->next;
		end = tmp;
	}
	return (1);
}
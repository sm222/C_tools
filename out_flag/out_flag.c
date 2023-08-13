/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouCt_t_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:42:39 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/13 20:42:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/C_tool.h"
#include "../Ct_lib/inc/Ct_get_next_line.h"

static size_t	Ct_str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	look_name(char *name , char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (Ct_strcmp(name, av[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	*s;
	short	cat;

	cat = 0;
	if (!Ct_flag_init())
	{
		Ct_err("main");
		return (1);
	}
	s = "t";
	printf(GRN"pipe a programe in this one, ctrl + D or C to stop"RESET"\n");
	while (s)
	{
		s = Ct_get_next_line(0);
		if (s)
		{
			if (s[Ct_str_len(s) - 1] == '\n')
				s[Ct_str_len(s) - 1] = 0;
			if (look_name(s, av, ac))
				cat++;
			else if (Ct_make_flag(s, cat) == -1)
				Ct_err("main");
			free(s);
		}
	}
	Ct_flag_end(1);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:42:39 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/13 20:42:39 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../C_tool.h"
#include "get_next_line.h"

static size_t	Ct_str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	main(void)
{
	char	*s;

	if (!Ct_flag_init())
	{
		Ct_err("main");
		return (1);
	}
	s = "t";
	printf(GRN"pipe a programe in this one, ctrl + D or C to stop"RESET"\n");
	while (s)
	{
		s = get_next_line(0);
		if (s)
		{
			if (s[Ct_str_len(s) - 1] == '\n')
				s[Ct_str_len(s) - 1] = 0;
			if (Ct_make_flag(s, 1) == -1)
				Ct_err("main");
			free(s);
		}
	}
	Ct_flag_end(1);
}
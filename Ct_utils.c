/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:10:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/07 16:14:28 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"

extern int	err_code;

const	char err_msg[6][30] = {
	"no err",
	"err malloc",
	"did't call flag_init",
	"can't make flag",
};

int	Ct_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static size_t	Ct_str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	Ct_put_str(char *s, int fd)
{
	return (write(fd, s, Ct_str_len(s)));
}

void	Ct_err(char *msg)
{
	Ct_put_str(msg, 2);
	Ct_put_str(": ", 2);
	Ct_put_str((char *)err_msg[err_code], 2);
	Ct_put_str("\n", 2);
}

void	*Ct_rt_ptr(void *ptr, int i)
{
	static void	*list[100];

	if (ptr && i > 0 && i < 101)
		list[i] = ptr;
	if (!ptr && i > 0 && i < 101)
		return (list[i]);
	return (NULL);
}

char	*Ct_strdup(char *s1)
{
	int		i;
	char	*new;

	if (!s1)
		return (NULL);
	i = Ct_str_len(s1);
	new = calloc(i++ + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (--i >= 0)
		new[i] = s1[i];
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:31:43 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 15:31:46 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ct_lib.h"

static char	*Ct_strfjoin(char *sfree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = Ct_strlen(sfree);
	s2_i = Ct_strlen(s2);
	new = Ct_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = Ct_free(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = sfree[s1_i];
	if (*new == 0)
		new = Ct_free(new);
	return (Ct_free(sfree), new);
}

static char	*Ct_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = Ct_calloc(1 + i, sizeof(char));
	if (!new)
		return (new = Ct_free(new));
	*cut = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

static char	Ct_find(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

/*
return line from fd
*/
char	*Ct_get_next_line(int fd)
{
	static char	*book[INT_MAX / 2];
	t_Ct_info		t_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > INT_MAX / 2)
		return (NULL);
	if (!book[fd])
		book[fd] = Ct_calloc(1, sizeof(char));
	t_val.tmp = Ct_calloc(BUFFER_SIZE + 1, sizeof(char));
	t_val.rv = 0;
	while (Ct_find(book[fd]) == '0')
	{
		Ct_bzero(t_val.tmp, BUFFER_SIZE + 1);
		t_val.rv = read(fd, t_val.tmp, BUFFER_SIZE);
		if (t_val.rv <= 0)
			break ;
		book[fd] = Ct_strfjoin(book[fd], t_val.tmp);
	}
	t_val.tmp = Ct_free(t_val.tmp);
	if (t_val.rv == -1 || (t_val.rv <= 0 && *book[fd] == 0))
		return (book[fd] = Ct_free(book[fd]), NULL);
	t_val.tmp = Ct_tiny_split(book[fd], &t_val.cut);
	t_val.tmp2 = book[fd];
	book[fd] = Ct_strfjoin(NULL, book[fd] + t_val.cut);
	return (Ct_free(t_val.tmp2), t_val.tmp);
}

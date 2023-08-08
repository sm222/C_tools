/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:30:18 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/08 12:56:38 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_strjoin(char *sfree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = Ct_strlen(sfree);
	s2_i = Ct_strlen(s2);
	new = Ct_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = Ct_sfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = sfree[s1_i];
	if (*new == 0)
		new = Ct_sfree(new);
	return (Ct_sfree(sfree), new);
}

char	*Ct_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = Ct_calloc(i + 1, sizeof(char));
	if (!new)
		return (new = Ct_sfree(new));
	*cut = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

char	Ct_find(char *s)
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

char	*get_next_line(int fd)
{
	static char	*book;
	t_info		t_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 500)
		return (book = Ct_sfree(book));
	if (!book)
		book = Ct_calloc(1, sizeof(char));
	t_val.tmp = Ct_calloc(BUFFER_SIZE + 1, sizeof(char));
	t_val.rv = 0;
	while (Ct_find(book) == '0')
	{
		Ct_bzero(t_val.tmp, BUFFER_SIZE + 1);
		t_val.rv = read(fd, t_val.tmp, BUFFER_SIZE);
		if (t_val.rv <= 0)
			break ;
		book = gnl_strjoin(book, t_val.tmp);
	}
	t_val.tmp = Ct_sfree(t_val.tmp);
	if (t_val.rv == -1 || (t_val.rv <= 0 && *book == 0))
		return (book = Ct_sfree(book), NULL);
	t_val.tmp = Ct_tiny_split(book, &t_val.cut);
	t_val.tmp2 = book;
	book = gnl_strjoin(NULL, book + t_val.cut);
	return (Ct_sfree(t_val.tmp2), t_val.tmp);
}

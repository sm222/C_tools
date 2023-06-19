/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:31:55 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	Ct_bzero(void *p, size_t size)
{
	while (size--)
		((char *)p)[size] = 0;
}

void	*Ct_sfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

void	*Ct_calloc(size_t size, size_t count)
{
	char	*new;

	new = malloc(size * count);
	if (!new)
		return (new = Ct_sfree(new));
	Ct_bzero(new, size * count);
	return (new);
}

size_t	Ct_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*Ct_strjoin(char *sfree, char *s2)
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

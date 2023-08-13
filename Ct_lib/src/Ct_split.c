/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:09:23 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

static void	Ct_allfree(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

static int	nb_word(const char *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

char	*Ct_strdup_c(const char *str, char c)
{
	size_t	i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new = Ct_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (i--)
		new[i] = str[i];
	return (new);
}

/// @brief split a sring on a spesific caracter
/// @param s input 
/// @param c carater
/// @return new double array
char	**Ct_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	new = (char **)Ct_calloc(nb_word(s, c) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (nb_word(s + i, c))
	{
		while (s[i] && s[i] == c)
			i++;
		new[index] = Ct_strdup_c(s + i, c);
		if (!new[index++])
			return (Ct_allfree(new), NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	return (new);
}

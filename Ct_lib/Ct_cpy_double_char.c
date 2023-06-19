/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_cpy_double_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:53:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ctlib.h"

/// @brief copy a double array
/// @param str input
/// @return new double array
char	**Ct_cpy_double_char(char **str)
{
	size_t	i;
	size_t	j;
	char	**new;

	i = 0;
	j = 0;
	new = NULL;
	if (!str)
		return (NULL);
	i = Ct_strlen_double(str);
	new = Ct_calloc(i + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (j < i)
	{
		new[j] = Ct_strdup(str[j]);
		if (!new[j])
		{
			Ct_double_sfree((void **)new);
			return (NULL);
		}
		j++;
	}
	return (new);
}

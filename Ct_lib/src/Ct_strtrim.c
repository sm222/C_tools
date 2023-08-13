/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:33:50 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/13 14:39:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

/*
trim the str form front and back
*/
char	*Ct_strtrim(char const *s1, char const *set)
{
	size_t	s_i;
	size_t	s_j;

	if (!s1 || !set)
		return (NULL);
	s_i = 0;
	s_j = Ct_strlen(s1);
	if (*s1 == 0)
		return (Ct_strdup(s1));
	while (Ct_strchr(set, (int)s1[s_i]) != NULL && s_i <= s_j)
		s_i++;
	while (Ct_strchr(set, (int)s1[s_j]) != NULL && s_i <= s_j)
		s_j--;
	return (Ct_substr(s1, s_i, (s_j - s_i + 1)));
}

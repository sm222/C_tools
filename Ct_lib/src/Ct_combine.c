/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_combine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:44:12 by anboisve          #+#    #+#             */
/*   Updated: 2023/08/18 11:34:06 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ct_lib.h"

char	*Ct_strfjoin(char *safefree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = Ct_strlen(safefree);
	s2_i = Ct_strlen(s2);
	new = Ct_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = Ct_free(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = safefree[s1_i];
	if (*new == 0)
		new = Ct_free(new);
	return (Ct_free(safefree), new);
}

static char	*Ct_add_c_to_s(char *s, char c)
{
	char	*new;
	int		i;

	i = Ct_strlen(s);
	new = Ct_calloc(i + 2, sizeof(char));
	Ct_memmove(new, s, i);
	new[i] = c;
	Ct_free(s);
	return (new);
}

static char	*Ct_add_arg(va_list list, char type)
{
	if (type == 's' || type == 'S')
		return (va_arg(list, char *));
	else if (type == 'd' || type == 'i')
		return (Ct_itoa(va_arg(list, int)));
	else if (type == 'u')
		return (Ct_ulltoa(va_arg(list, unsigned int), 10));
	else if (type == 'x' || type == 'p')
		return (Ct_ulltoa(va_arg(list, unsigned long), 16));
	else if (type == '%')
		return (Ct_strdup("%"));
	return (NULL);
}

static char	*Ct_add_str(va_list list, char type, char *s)
{
	char	*tmp;

	if (type == 'c')
		return (Ct_add_c_to_s(s, va_arg(list, int)));
	tmp = Ct_add_arg(list, type);
	s = Ct_strfjoin(s, tmp);
	if (type != 's')
		Ct_free(tmp);
	return (s);
}

char	*Ct_combine(char *s, va_list arg)
{
	size_t	i;
	char	*new;

	i = 0;
	new = Ct_calloc(1, sizeof(char));
	while (s && s[i])
	{
		if (s[i] != '%')
		{
			new = Ct_add_c_to_s(new, s[i]);
			if (!new)
				return (NULL);
		}
		else
		{
			new = Ct_add_str(arg, s[++i], new);
			if (!new)
				return (NULL);
		}
		i++;
	}
	va_end(arg);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:10:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/07/05 14:38:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/C_tool.h"

extern int	Ct_err_code;

const char Ct_err_msg[100][50] = {
	"no err",
	"err malloc",
	"did't call flag_init",
	"can't make flag",
	"call flag_init more that once",
	"call flag_end with no flag",
	"call flag_print with no flag",
	"make a flag with a negative number",
	"call flag_print with no flag_init",
	"call flag_end with no flag",
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

size_t	Ct_str_len(const char *s)
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

/// @brief tell what ft did't work well
/// @param msg tell where the problem occur
void	Ct_err(char *msg)
{
	Ct_printf(2, "%o%s: %s\n", NULL, msg, (char *)Ct_err_msg[Ct_err_code]);
}

/// @brief return 
/// @param ptr input adrres
/// @param i give the index of the adrres you want
/// @return return the adress ask
void	*Ct_rt_ptr(void *ptr, int i)
{
	static void	*list[100];

	if (ptr && i > 0 && i < 101)
		list[i] = ptr;
	if (!ptr && i > 0 && i < 101)
		return (list[i]);
	if (i < 0 && i > -101)
		list[i * -1] = NULL;
	return (NULL);
}

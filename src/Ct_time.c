/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:29:19 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/08 21:29:19 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "C_tool.h"
#include "utile.h"
#include <time.h>

extern int	Ct_err_code;

void	Ct_time_print(void)
{
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("\r%s", asctime(timeinfo));
}

char	*Ct_time_return(void)
{
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	return(asctime(timeinfo));
}
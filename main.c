/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:40:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/09 18:40:49 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "C_tool.h"

int	main(void)
{
	flag_init();
	printf("make flag * %d\n", make_flag("test"));
	printf("make flag * %d\n", make_flag("test"));
	flag_end();
	Ct_err("main");

	char s[10];
	s++;
}
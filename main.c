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
<<<<<<< HEAD
	
	static char	*str;

	if (!str)
		str = calloc(1, 1);

=======
	flag_init();
	printf("make flag * %d\n", make_flag("test"));
	printf("make flag * %d\n", make_flag("test"));
	flag_end();
	Ct_err("main");

	char s[10];
	s++;
>>>>>>> refs/remotes/origin/main
}
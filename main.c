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

/*
	Ct_flag_init();
	Ct_make_flag(name);
	Ct_flag_end();

	void	Ct_mprintf(void *ptr, size_t size, int type, int name)
	void	Ct_memcmp(void *ptr1, void *ptr2, size_t size, int type)

	void	Ct_err(char *msg)
*/

int	main(void)
{
	Ct_err("main");
	for (size_t i = 0; i < 10; i++)
	{
		
		Ct_time_print();
		sleep(1);
	}
	
	return 0;
}

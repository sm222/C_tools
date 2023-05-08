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
	// flag - fist: start with flag init
	Ct_flag_init();
	// second: make flag as you want
	Ct_make_flag("one", 1);
	Ct_make_flag("two", 2);
	Ct_make_flag("three", 1);
	Ct_make_flag("three", 3);
	Ct_make_flag("three", 3);
	Ct_make_flag("two", 2);
	Ct_make_flag("im also twe", 2);
	// last: print all the flag use and free them
	//use to print the memorry of 2 poiter to cmper them
	Ct_flag_print(1);
	Ct_flag_print(2);
	Ct_flag_end(-1);
	Ct_memcmp(&Ct_flag_init, &Ct_flag_end, 10, 0);

	//use to print memorry of a array
	Ct_mprintf("this is a string\r\b\t\n\v\a", 23, 1, 'A');

	//use to see the err make in Ct ft
	Ct_err("main");
}
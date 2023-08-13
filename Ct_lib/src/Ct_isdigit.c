/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:11:00 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
return the char if it is a char betwen 0 and 9 else return 0
*/
int	Ct_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

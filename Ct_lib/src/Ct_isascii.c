/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:21:55 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
return the char if it is a ascii else return 0
*/
int	Ct_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

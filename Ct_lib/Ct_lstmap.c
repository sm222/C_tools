/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:12:24 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 17:11:52 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ctlib.h"

t_list	*Ct_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_tmp;
	t_list	*list;
	void	*stuff;

	list = NULL;
	while (lst)
	{
		stuff = (f(lst->content));
		new_tmp = Ct_lstnew(stuff);
		if (!new_tmp)
		{
			Ct_lstclear(&list, del);
			free (stuff);
			return (NULL);
		}
		Ct_lstadd_back(&list, new_tmp);
		lst = lst->next;
	}
	return (list);
}

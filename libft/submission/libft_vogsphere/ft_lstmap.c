/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:38:51 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 21:15:48 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *begin;

	begin = f(lst);
	new_lst = begin;
	if (lst != NULL && f != NULL)
	{
		while (lst->next)
		{
			lst = lst->next;
			new_lst->next = f(lst);
			if (new_lst->next == NULL)
				return (NULL);
			new_lst = new_lst->next;
		}
		new_lst->next = NULL;
	}
	return (begin);
}

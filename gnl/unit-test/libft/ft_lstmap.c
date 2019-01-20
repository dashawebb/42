/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:38:51 by creek             #+#    #+#             */
/*   Updated: 2019/01/14 16:23:16 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(void *content, size_t size)
{
	free(content);
	size = 0;
}

void (*del)(void *, size_t);

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *begin;

	del = &ft_free;
	begin = f(lst);
	new_lst = begin;
	if (lst != NULL && f != NULL)
	{
		while (lst->next)
		{
			lst = lst->next;
			new_lst->next = f(lst);
			if (new_lst->next == NULL)
			{
				ft_lstdel(&begin, del);
				return (NULL);
			}
			new_lst = new_lst->next;
		}
		new_lst->next = NULL;
	}
	return (begin);
}

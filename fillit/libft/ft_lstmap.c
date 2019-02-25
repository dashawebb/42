/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:53:09 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/08 15:24:54 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*applied;

	if (lst == NULL)
		return (NULL);
	applied = f(lst);
	new = applied;
	while (lst->next)
	{
		lst = lst->next;
		if ((applied->next = f(lst)) == NULL)
		{
			free(applied->next);
			return (NULL);
		}
		applied = applied->next;
	}
	return (new);
}

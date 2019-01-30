/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:50:53 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 21:11:15 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst != NULL && del != NULL)
	{
		while ((*alst) != NULL)
		{
			del((*alst)->content, (*alst)->content_size);
			tmp = (*alst)->next;
			free(*alst);
			*alst = tmp;
		}
	}
}

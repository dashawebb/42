/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:57:57 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 16:02:04 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	del_queue(t_rbtree *elem)
{
	if (elem->content_size == 0)
		return ;
	free(elem->content);
}

void	del_tree(t_rbtree *elem)
{
	t_data	*el;

	if (elem->content_size == 0)
		return ;
	el = (t_data *)elem->content;
	free(el->name);
	if (g_flags->l)
	{
		free(el->perms);
		free(el->user);
		free(el->group);
		free(el->time);
		if (el->link)
			free(el->link);
		el->acl = 0;
		el->xattr = 0;
	}
	free(el);
}

void	ft_set_id(t_rbtree *root, size_t *n)
{
	if (root->left->content)
		ft_set_id(root->left, n);
	if (root->content)
	{
		((t_data *)root->content)->id = *n;
		*n = *n + 1;
	}
	if (root->right->content)
		ft_set_id(root->right, n);
}

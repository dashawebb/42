/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:56:57 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/22 16:38:19 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		name_tree_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
	if (!g_flags->r)
		return (ft_strcmp(((t_data *)elem1->content)->name, \
											((t_data *)elem2->content)->name));
		return (ft_rev_strcmp(((t_data *)elem1->content)->name, \
											((t_data *)elem2->content)->name));
}

static int		time_tree_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
	size_t	tmp;

	if (!g_flags->r)
	{
		tmp = ((t_data *)elem2->content)->stime - \
											((t_data *)elem1->content)->stime;
		if (tmp == 0)
			return (name_tree_cmp(elem1, elem2));
		return (tmp);
	}
	tmp = ((t_data *)elem1->content)->stime - ((t_data *)elem2->content)->stime;
	if (tmp == 0)
		return (name_tree_cmp(elem1, elem2));
	return (tmp);
}

static int		doesnt_sorted_tree_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
	if (!elem1 || !elem2)
		return (0);
	return (0);
}

int				select_tree_sort(t_rbtree **tree, t_rbtree *new)
{
	if (!new || !tree)
		return (0);
	if (g_flags->t)
	{
		ft_rbtadd(tree, new, time_tree_cmp);
		return (1);
	}
	if (g_flags->f)
	{
		ft_rbtadd(tree, new, doesnt_sorted_tree_cmp);
		return (1);
	}
	ft_rbtadd(tree, new, name_tree_cmp);
	return (1);
}

int				ft_cmp_id(t_rbtree *elem1, t_rbtree *elem2)
{
	if (((t_data *)elem1->content)->id < ((t_data *)elem2->content)->id)
		return (-1);
	if (((t_data *)elem1->content)->id > ((t_data *)elem2->content)->id)
		return (1);
	return (0);
}

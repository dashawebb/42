/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:51:25 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 16:03:13 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		name_queue_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
	if (!g_flags->r)
		return (ft_strcmp(elem1->content, elem2->content));
	return (ft_rev_strcmp(elem1->content, elem2->content));
}

static int		reverse_time_queue_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
	struct stat	stats;
	time_t		time1;
	time_t		time2;
	size_t		tmp;

	if (lstat((char *)elem1->content, &stats) == -1)
		time1 = 0;
	else
		time1 = stats.st_mtimespec.tv_sec;
	if (lstat((char *)elem2->content, &stats) == -1)
		time2 = 0;
	else
		time2 = stats.st_mtimespec.tv_sec;
	tmp = time1 - time2;
	if (tmp == 0)
		return (name_queue_cmp(elem1, elem2));
	return (tmp);
}

static int		doesnt_sorted_queue_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
	if (elem1 || elem2)
		return (0);
	return (0);
}

static int		time_queue_cmp(t_rbtree *elem1, t_rbtree *elem2)
{
	struct stat	stats;
	time_t		time1;
	time_t		time2;
	size_t		tmp;

	if (!g_flags->r)
	{
		if (lstat((char *)elem1->content, &stats) == -1)
			time1 = 0;
		else
			time1 = stats.st_mtimespec.tv_sec;
		if (lstat((char *)elem2->content, &stats) == -1)
			time2 = 0;
		else
			time2 = stats.st_mtimespec.tv_sec;
		tmp = time2 - time1;
		if (tmp == 0)
			return (name_queue_cmp(elem1, elem2));
		return (tmp);
	}
	return (reverse_time_queue_cmp(elem1, elem2));
}

int				select_queue_sort(t_rbtree **queue, t_rbtree *new)
{
	if (!new || !queue)
		return (0);
	if (g_flags->t)
	{
		ft_rbtadd(queue, new, time_queue_cmp);
		return (1);
	}
	if (g_flags->f)
	{
		ft_rbtadd(queue, new, doesnt_sorted_queue_cmp);
		return (1);
	}
	ft_rbtadd(queue, new, name_queue_cmp);
	return (1);
}

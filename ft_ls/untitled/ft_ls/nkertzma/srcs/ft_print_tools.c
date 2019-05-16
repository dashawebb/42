/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:52:22 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/22 16:31:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_size(t_data *data)
{
	int		space;

	space = g_info->size_width - ft_diglen(data->size);
	while (space-- > 0)
		write(1, " ", 1);
	if (!data->major && !data->minor)
	{
		ft_putnbr(data->size);
		if (g_info->mm)
		{
			space = g_info->maj_width + g_info->min_width + 3;
			while (space-- > 0)
				write(1, " ", 1);
		}
	}
	else
	{
		ft_putnbr(data->major);
		write(1, ", ", 2);
		ft_putnbr(data->minor);
		space = g_info->maj_width + g_info->min_width + 2 - \
								ft_diglen(data->major) - ft_diglen(data->minor);
		while (space-- > 0)
			write(1, " ", 1);
	}
}

void	print_user(t_data *data)
{
	int		space;

	if (!g_flags->g)
	{
		write(1, data->user, ft_strlen(data->user));
		space = g_info->user_width - ft_strlen(data->user);
		while (space-- > 0)
			write(1, " ", 1);
		write(1, "  ", 2);
	}
	if (!g_flags->o)
	{
		write(1, data->group, ft_strlen(data->group));
		space = g_info->group_width - ft_strlen(data->group);
		while (space-- > 0)
			write(1, " ", 1);
		write(1, "  ", 2);
	}
}

void	print_perms(t_data *data)
{
	int		space;

	write(1, data->perms, ft_strlen(data->perms));
	if (data->xattr)
		write(1, "@", 1);
	else if (data->acl)
		write(1, "+", 1);
	else if (g_info->ext)
		write(1, " ", 1);
	write(1, "  ", 2);
	space = g_info->links_width - ft_diglen(data->links);
	while (space-- > 0)
		write(1, " ", 1);
	ft_putnbr(data->links);
}

void	print_list(t_data *data)
{
	print_perms(data);
	write(1, " ", 1);
	print_user(data);
	print_size(data);
	write(1, " ", 1);
	write(1, data->time, ft_strlen(data->time));
	write(1, " ", 1);
	write(1, data->name, ft_strlen(data->name));
	if (data->link)
	{
		write(1, " -> ", 4);
		write(1, data->link, ft_strlen(data->link));
	}
	write(1, "\n", 1);
}

void	print_data(t_rbtree *elem)
{
	if (g_flags->l || g_flags->o)
	{
		print_list((t_data *)elem->content);
		return ;
	}
	if (g_flags->one)
	{
		ft_putendl(((t_data *)elem->content)->name);
		return ;
	}
}

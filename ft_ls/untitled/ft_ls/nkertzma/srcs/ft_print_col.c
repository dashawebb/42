/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:48:41 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/22 15:56:01 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	ft_max_len(t_rbtree *root)
{
	size_t	lsize;
	size_t	rsize;
	size_t	csize;

	if (!root->content)
		return (0);
	csize = ft_strlen(((t_data *)root->content)->name);
	if (!(root->left->content) && !(root->right->content))
		return (csize);
	lsize = root->left->content ? ft_max_len(root->left) : 0;
	rsize = root->right->content ? ft_max_len(root->right) : 0;
	if ((csize > lsize) && (csize > rsize))
		return (csize);
	return (rsize > lsize ? rsize : lsize);
}

static void		ft_printf_elem_in_col_v(t_rbtree *root, size_t rcl[2],
		size_t *n)
{
	t_rbtree	*elem;
	t_rbtree	*find;
	t_data		data;
	char		*str;
	size_t		count;

	count = rcl[RCL_C] * rcl[RCL_R];
	find = ft_rbtnew0(&data, sizeof(data));
	while (*n < count)
	{
		(CNT(find))->id = (*n % rcl[RCL_C]) * rcl[RCL_R] + (*n / rcl[RCL_C]);
		if ((elem = ft_rbtfind(root, find, ft_cmp_id)))
		{
			str = ft_strnew(rcl[RCL_L]);
			ft_memset(str, ' ', rcl[RCL_L]);
			ft_memmove(str, CNT(elem)->name, ft_strlen(CNT(elem)->name));
			((*n + 1) % rcl[RCL_C]) ? ft_putstr(str) : ft_putendl(str);
			free(str);
		}
		else
			ft_putchar('\n');
		*n = *n + 1;
	}
	free(find->content);
	free(find);
}

static void		ft_printf_elem_in_col_h(t_rbtree *root, size_t rcl[3],
		size_t *n)
{
	char	*str;
	size_t	width;
	size_t	columns;

	width = rcl[RCL_L];
	columns = rcl[RCL_C];
	if (root->left->content)
		ft_printf_elem_in_col_h(root->left, rcl, n);
	if (root->content)
	{
		str = ft_strnew(width);
		ft_memset(str, ' ', width);
		ft_memmove(str, ((t_data *)root->content)->name,
				ft_strlen(((t_data *)root->content)->name));
		((*n + 1) % columns) ? ft_putstr(str) : ft_putendl(str);
		*n = *n + 1;
		free(str);
	}
	if (root->right->content)
		ft_printf_elem_in_col_h(root->right, rcl, n);
}

static void		print_columns(t_rbtree *info, size_t width, char is_horisontal)
{
	size_t rcl[3];
	size_t n;

	rcl[RCL_L] = ft_max_len(info) + 1;
	rcl[RCL_C] = rcl[RCL_L] > width ? 1 : (width / rcl[RCL_L]);
	n = ft_rbtsize(info);
	rcl[RCL_R] = n / rcl[RCL_C] + ((n % rcl[RCL_C]) ? 1 : 0);
	while (rcl[RCL_R] * (rcl[RCL_C] - 1) >= n)
		rcl[RCL_C]--;
	n = 0;
	if (is_horisontal)
		ft_printf_elem_in_col_h(info, rcl, &n);
	else
	{
		ft_set_id(info, &n);
		n = 0;
		ft_printf_elem_in_col_v(info, rcl, &n);
	}
	(rcl[RCL_L] && (n % rcl[RCL_C])) ? ft_putchar('\n') : (void)0;
}

void			print_tree(t_rbtree *tree)
{
	struct winsize	mywinsize;
	int				ttyfd;

	if (g_flags->l || g_flags->o)
	{
		write(1, "total ", 6);
		ft_putnbr(g_info->blocks);
		write(1, "\n", 1);
		ft_rbtforeach(tree, print_data, INFIX);
		return ;
	}
	if (g_flags->one)
		ft_rbtforeach(tree, print_data, INFIX);
	else if ((ttyfd = open("/dev/tty", O_RDWR | O_NOCTTY)) == -1)
		print_columns(tree, DEF_SZ, g_flags->x ? COL_H : COL_V);
	else
	{
		if (ioctl(ttyfd, TIOCGWINSZ, &mywinsize) == -1)
			print_columns(tree, DEF_SZ, g_flags->x ? COL_H : COL_V);
		else
			print_columns(tree, mywinsize.ws_col, g_flags->x ? COL_H : COL_V);
		close(ttyfd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 10:33:03 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 17:09:00 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Follow functions reading folders and fill red-black tree "tree" which stores
** structure "t_data"
*/

static void	fill_tree(t_rbtree **tree, struct dirent *cdir, char *path)
{
	t_data		*new;

	if (cdir->d_name[0] == '.' && !g_flags->a && !g_flags->b_a)
		return ;
	if (cdir->d_name[0] == '.' && cdir->d_name[1] == '.' && g_flags->b_a)
		return ;
	if (!(new = (t_data *)malloc(sizeof(t_data))))
		handle_error(E_MLLC_CRSH, NULL);
	if (cdir->d_type == 4 && g_flags->p)
		new->name = ft_strjoin(cdir->d_name, "/");
	else
		new->name = ft_strdup(cdir->d_name);
	if (!new->name)
		handle_error(E_MLLC_CRSH, NULL);
	if (!try_fill_list(new, cdir, path))
		return ;
	if (!select_tree_sort(tree, ft_rbtnew(new, sizeof(*new))))
		handle_error(E_MLLC_CRSH, NULL);
	free(new);
}

static void	fill_queue(t_rbtree **queue, char *npath, char *cpath)
{
	char		*path;
	int			res;

	if (npath[0] == '.' && !g_flags->a)
		return ;
	if (ft_strcmp(npath, ".") == 0 || ft_strcmp(npath, "..") == 0)
		return ;
	if (!(path = ft_strjoin(cpath, npath)))
		handle_error(E_MLLC_CRSH, NULL);
	res = select_queue_sort(queue, ft_rbtnew(path, ft_strlen(path) + 1));
	ft_strdel(&path);
	if (!res)
		handle_error(E_MLLC_CRSH, NULL);
}

static void	while_dir(t_rbtree *elem, DIR *dirp, t_rbtree **tree, \
													t_rbtree **queue)
{
	struct dirent	*cdir;
	char			*path;

	*tree = NULL;
	*queue = NULL;
	init_info();
	if (ft_strcmp((char *)elem->content, "/"))
		path = ft_strjoin(elem->content, "/");
	else
		path = ft_strdup((char *)elem->content);
	while ((cdir = readdir(dirp)))
	{
		fill_tree(tree, cdir, path);
		if (g_flags->y && cdir->d_type == 4)
			fill_queue(queue, cdir->d_name, path);
	}
	free(path);
}

void		handle_opendir(t_rbtree *elem)
{
	if (errno == ENOTDIR)
	{
		write(1, (char *)elem->content, ft_strlen((char *)elem->content));
		write(1, "\n", 1);
		return ;
	}
	handle_errno((char *)elem->content);
}

void		read_dir(t_rbtree *elem)
{
	DIR				*dirp;
	t_rbtree		*tree;
	t_rbtree		*queue;

	if (!(dirp = opendir((char *)elem->content)))
	{
		handle_opendir(elem);
		return ;
	}
	if (ft_strcmp((char *)elem->content, "."))
	{
		write(1, (char *)elem->content, ft_strlen((char *)elem->content));
		write(1, ":\n", 2);
	}
	while_dir(elem, dirp, &tree, &queue);
	closedir(dirp);
	if (ft_rbtlen(tree) > 0)
		print_tree(tree);
	if ((g_flags->y && ft_rbtlen(queue) > 0) || ft_rbtlen(ft_rbtroot(elem)) > 1)
		write(1, "\n", 1);
	free(g_info);
	g_info = NULL;
	ft_rbtclr(&tree, del_tree);
	if (g_flags->y && queue)
		render(queue);
}

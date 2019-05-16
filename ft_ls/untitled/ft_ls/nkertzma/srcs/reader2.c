/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:42:33 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 16:46:58 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_acl(t_data *data, struct stat stats, char *path)
{
	char			buf[1];
	acl_t			buf2;

	data->acl = 0;
	data->xattr = 0;
	data->major = 0;
	data->minor = 0;
	if (listxattr(path, buf, 0, XATTR_NOFOLLOW))
		data->xattr = 1;
	if (errno == ERANGE)
		data->xattr = 1;
	if ((buf2 = acl_get_link_np(path, ACL_TYPE_EXTENDED)) != NULL)
	{
		data->acl = 1;
		acl_free(buf2);
	}
	if (data->perms[0] == 'c' || data->perms[0] == 'b')
	{
		data->major = major(stats.st_rdev);
		data->minor = minor(stats.st_rdev);
	}
	if (ft_diglen(data->major) > g_info->maj_width)
		g_info->maj_width = ft_diglen(data->major);
	if (ft_diglen(data->minor) > g_info->min_width)
		g_info->min_width = ft_diglen(data->minor);
}

void	fill_list(t_data *data, struct stat stats, char *path)
{
	int				res;

	data->group = NULL;
	fill_perms(data, stats);
	fill_time(data, stats);
	data->link = NULL;
	g_info->blocks += (unsigned int)stats.st_blocks;
	data->links = stats.st_nlink;
	data->size = stats.st_size;
	if (!(data->user = ft_strdup(getpwuid(stats.st_uid)->pw_name)))
		handle_error(E_MLLC_CRSH, NULL);
	if (!(data->group = ft_strdup(getgrgid(stats.st_gid)->gr_name)))
		handle_error(E_MLLC_CRSH, NULL);
	fill_info(data);
	if ((stats.st_mode & S_IFMT) == S_IFLNK)
	{
		if (!(data->link = (char *)malloc(sizeof(char) * 1000)))
			handle_error(E_MLLC_CRSH, NULL);
		if ((res = readlink(path, data->link, 1000)) == -1)
			data->link = NULL;
		else
			data->link[res] = '\0';
	}
	fill_acl(data, stats, path);
}

int		try_fill_list(t_data *new, struct dirent *cdir, char *path)
{
	struct stat	stats;
	char		*npath;

	if (!(npath = ft_strjoin(path, cdir->d_name)))
		handle_error(E_MLLC_CRSH, NULL);
	if (g_flags->l || g_flags->t || g_flags->o)
	{
		if (lstat(npath, &stats) != -1)
			fill_list(new, stats, npath);
		else
		{
			ft_strdel(&(new->name));
			free(new);
			handle_errno(npath);
			ft_strdel(&npath);
			return (0);
		}
	}
	ft_strdel(&npath);
	if (new->acl || new->xattr)
		g_info->ext = 1;
	if (new->major || new->minor)
		g_info->mm = 1;
	return (1);
}

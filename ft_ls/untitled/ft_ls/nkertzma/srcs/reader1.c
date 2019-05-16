/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:39:48 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 16:55:52 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_info(void)
{
	if (!(g_info = (t_info *)malloc(sizeof(t_info))))
		handle_error(E_MLLC_CRSH, NULL);
	g_info->links_width = 0;
	g_info->size_width = 0;
	g_info->user_width = 0;
	g_info->group_width = 0;
	g_info->blocks = 0;
	g_info->ext = 0;
	g_info->maj_width = 0;
	g_info->min_width = 0;
	g_info->mm = 0;
}

void	fill_time(t_data *data, struct stat stats)
{
	char	*time;

	data->stime = stats.st_mtimespec.tv_sec;
	if (g_flags->u && !g_flags->c && !g_flags->b_u)
		data->stime = stats.st_atimespec.tv_sec;
	if (!g_flags->u && g_flags->c && !g_flags->b_u)
		data->stime = stats.st_ctimespec.tv_sec;
	if (!g_flags->u && !g_flags->c && g_flags->b_u)
		data->stime = stats.st_birthtimespec.tv_sec;
	time = ctime(&(data->stime));
	if (!g_flags->b_t)
	{
		if (!(data->time = ft_strsub(time, 4, 12)))
			handle_error(E_MLLC_CRSH, NULL);
	}
	else
	{
		if (!(data->time = ft_strdup(time + 4)))
			handle_error(E_MLLC_CRSH, NULL);
		data->time[20] = '\0';
	}
	if (!g_flags->t)
		data->stime = stats.st_mtimespec.tv_sec;
}

void	fill_file_type(t_data *data, int mode)
{
	mode == S_IFREG ? (data->perms[0] = '-') : (0);
	mode == S_IFDIR ? (data->perms[0] = 'd') : (0);
	mode == S_IFCHR ? (data->perms[0] = 'c') : (0);
	mode == S_IFBLK ? (data->perms[0] = 'b') : (0);
	mode == S_IFIFO ? (data->perms[0] = 'p') : (0);
	mode == S_IFLNK ? (data->perms[0] = 'l') : (0);
	mode == S_IFSOCK ? (data->perms[0] = 's') : (0);
}

void	fill_perms(t_data *data, struct stat stats)
{
	int		mode;

	mode = stats.st_mode & S_IFMT;
	if (!(data->perms = ft_strnew(12)))
		handle_error(E_MLLC_CRSH, NULL);
	fill_file_type(data, mode);
	data->perms[1] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
	data->perms[2] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
	data->perms[3] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
	data->perms[4] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
	data->perms[5] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
	data->perms[6] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
	data->perms[7] = (stats.st_mode & S_IROTH) ? 'r' : '-';
	data->perms[8] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
	data->perms[9] = (stats.st_mode & S_IXOTH) ? 'x' : '-';
	if (stats.st_mode & S_ISUID)
		data->perms[3] = (data->perms[3] == 'x') ? 's' : 'S';
	if (stats.st_mode & S_ISGID)
		data->perms[6] = (data->perms[6] == 'x') ? 's' : 'S';
	if (stats.st_mode & S_ISVTX)
		data->perms[9] = (data->perms[9] == 'x') ? 't' : 'T';
}

void	fill_info(t_data *data)
{
	unsigned int	tmp;

	if ((tmp = ft_diglen(data->links)) > g_info->links_width)
		g_info->links_width = tmp;
	if ((tmp = ft_strlen(data->user)) > g_info->user_width)
		g_info->user_width = tmp;
	if ((tmp = ft_strlen(data->group)) > g_info->group_width)
		g_info->group_width = tmp;
	if ((tmp = ft_diglen(data->size)) > g_info->size_width)
		g_info->size_width = tmp;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/26 19:41:05 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		line_yep(char **buf, char **line, int fd)
{
	char	*tmp_buf;
	size_t	i;

	i = 0;
	while (buf[fd][i] != '\n' && buf[fd][i] != '\0')
		i++;
	if (buf[fd][0] == '\0')
		return (0);
	if (buf[fd][i] == '\n' || !(buf[fd][i + 1]))
	{
		*line = ft_strsub(buf[fd], 0, i);
		if (!(tmp_buf = ft_strdup(buf[fd] + i + 1)))
			tmp_buf = ft_strnew(0);
		free(buf[fd]);
		buf[fd] = tmp_buf;
		return (1);
	}
	else if (buf[fd][i] == '\0')
	{
		*line = ft_strdup(buf[fd]);
		ft_strdel(&buf[fd]);
	}
	return (1);
}

int		buf_writing(char **buf, int fd, char *read_buf)
{
	char *tmp_buf;

	if (buf[fd] == NULL)
		buf[fd] = ft_strnew(1);
	if (!(tmp_buf = ft_strjoin(buf[fd], read_buf)))
		return (-1);
	free(buf[fd]);
	buf[fd] = tmp_buf;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char *buf[4864];
	char		read_buf[BUFF_SIZE + 1];

	if (!line || fd < 0 || BUFF_SIZE < 0 || (ret = read(fd, read_buf, 0)) < 0)
		return (-1);
	while (1)
	{
		ret = read(fd, read_buf, BUFF_SIZE);
		read_buf[ret] = '\0';
		if (ret == 0)
			return (buf[fd] ? (line_yep(buf, line, fd)) : 0);
		while (ret > 0)
		{
			if ((buf_writing(buf, fd, read_buf)))
				return (-1);
			if (ft_strchr(buf[fd], '\n'))
				return (line_yep(buf, line, fd));
			else
				break ;
		}
	}
	return (1);
}

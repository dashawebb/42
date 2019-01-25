/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/25 21:56:11 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		line_yep(char **buf, char **line)
// {
// 	char	*tmp_buf;
// 	char	*i;
//
// 	if (**buf == '\0')
// 		return (0);
// 	if ((i = ft_strchr(*buf, '\n')))
// 	{
// 		*line = ft_strsub(*buf, 0, i - *buf);
// 		tmp_buf = ft_strdup(i + 1);
// 		free(*buf);
// 		*buf = tmp_buf;
// 	}
// 	else
// 	{
// 		*line = ft_strdup(*buf);
// 		free(*buf);
// 		*buf = ft_strnew(1);
// 	}
// 	return (1); // line has been read
// }

{
	char *tmp_buf;
	int i;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[0] == '\0')
		return (0);
	if (buf[i] == '\n')
	{
		*line = ft_strsub(buf[fd], 0, i);
		tmp_buf = ft_strdup(buf[fd] + i + 1);
		free(buf[fd]);
		buf[fd] = tmp_buf;
		return (1);
	}
	else if(buf[i] == '\0')
	{
		*line = ft_strdup(*buf);
		ft_strdel(buf);
		return(0);
	}
}

int		get_next_line(const int fd, char **line)
{
	int ret;

	static char *buf[4864]; // сколько FD указать?
	char *tmp_buf; /* какой размер ему указать? нужен ли статический размер? или мы его все время используем в маллочных функциях, поэтому размер не нужен? */
	char read_buf[BUFF_SIZE + 1];
	if (!line || fd < 0 || (ret = read(fd, read_buf, 0)) < 0)
		return (-1);
	while (1) // или while ret?
	{
		ret = read(fd, read_buf, BUFF_SIZE);
		read_buf[ret] = '\0'; // нужно ли это?
		if (ret == 0)
				return (line_yep(&(buf[fd]), line));
		while (ret > 0)
		{
			if (buf[fd] == NULL)
				buf[fd] = ft_strnew(1);
			if (!(tmp_buf = ft_strjoin(buf[fd], read_buf))) // арунте считает, что тут будут утечки
				return (-1);
			free(buf[fd]);
			buf[fd] = tmp_buf;
			if (ft_strchr(buf[fd], '\n') || ft_strchr(buf[fd], '\0')) // нужна ли вторая проверка?
				return (line_yep(&(buf[fd]), line));
		}
	//	if (ret == 0)
	//		break ;
	}
	// while (buf[fd][i] != '\n' && buf[fd][i] != '\0')
	// 	i++;
	// if (buf[fd][0] == '\0')
	// 	return (0);
	// *line = ft_strsub(buf[fd], 0, i);
	// tmp_buf = ft_strdup(buf[fd] + i + 1);
	// free(buf[fd]);
	// buf[fd] = tmp_buf;
	// return (1); // line has been read
}

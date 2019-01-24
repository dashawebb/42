/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/24 22:14:28 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int cut_line(char **buf, int fd, char **line);

int		get_next_line(const int fd, char **line)
{
	int ret;
	static char *buf[255]; // сколько FD указать?
	char *tmp_buf; /* какой размер ему указать? нужен ли статический размер? или мы его все время используем в маллочных функциях, поэтому размер не нужен? */
	char read_buf[BUFF_SIZE + 1];
	if (!line || fd < 0 || (ret = read(fd, read_buf, 0)) < 0)
		return (-1);
	while ((ret = read(fd, read_buf, BUFF_SIZE)))
	{
		read_buf[ret] = '\0';
		if (buf[fd] == NULL)
			buf[fd] = ft_strnew(1);
		if (!(tmp_buf = ft_strjoin(buf[fd], read_buf))) // арунте считает, что тут будут утечки
			return (-1);
		free(buf[fd]);
		buf[fd] = tmp_buf;
		if (ft_strchr(read_buf, '\n') || ft_strchr(read_buf, '\0')) // нужна ли вторая проверка?
			break ;
	}

	printf("%s -- а тут tmp_buf\n", tmp_buf);
	printf ("%s -- вот это read_buf\n", read_buf);
	printf("%s -- a вот это буф[fd]\n", buf[fd]);
	if (ret != 0 || ((buf[fd] != NULL) && (buf[fd][0] != '\0')))
		return(cut_line(&buf[fd], fd, line));
	else
		return (0); // ПОЧЕМУ ТЫ НИКОГДА СЮДА НЕ ЗАХОДИШЬ СУЧКА
	//return(reading(buf, fd, line)); //вот это надо куда-то присвоить
	// if (ret == 0 && (buf[fd] == NULL || buf[fd][0] == '\0')) // сюда этот пидор не заходит. Ну и понятно, потому что у меня всегда возвращается 1
	// 	return (0); // tut EOF
	return (1);//чтобы компилятор отъебался
}

int cut_line(char **buf, int fd, char **line)
{
	int i;
	int len;
	char *tmp;
	i = 0;
	len = 0;
	while (buf[fd][i] != '\n' && buf[fd][i] != '\0')
	{
		len++;
		i++;
	}
	*line = ft_strsub(buf[fd], 0, len);
	tmp = ft_strdup(buf[fd] + len + 1);
	free(buf[fd]);
	buf[fd] = tmp;
	return (1); // line has been read
}

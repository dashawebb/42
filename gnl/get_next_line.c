/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/20 18:01:59 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//
// int error_check()
// {
//
//
//
//
// }
int		get_next_line(const int fd, char **line)
{
  char read_buf[BUFF_SIZE + 1];
  static char *buf[255];
  char *tmp_buf; /* какой размер ему указать? нужен ли статический размер? или мы его все время используем в маллочных функциях, поэтому размер не нужен? */
  int ret;
  int len = 0;
  int i = 0;
  ret = 1;
  if (!line || /*BUFF_SIZE <= 0 ||*/ fd < 0 || (ret = read(fd, read_buf, 0)) < 0)
	return (-1);
  while ((ret = read(fd, read_buf, BUFF_SIZE)))
  {
	  read_buf[ret] = '\0';
	  if (ret == -1)
	  {
//		  printf("OH NO! Terrible mistake. Read() exited with code -1\n");
		  return (-1); //
	  }
	  if (ret < BUFF_SIZE)
	  {
		printf("тогда конец файла");
		return (0);//эту проверку нужно в другое место захуячить
		}
	  if (buf[fd] == NULL)
			buf[fd] = ft_strnew(1);
	if (!(tmp_buf = ft_strjoin(buf[fd], read_buf)))
		return (-1);
	  free(buf[fd]);
	  buf[fd] = tmp_buf;
	  if (ft_strchr(read_buf, '\n') || ft_strchr(read_buf, '\0')) // нужна ли вторая проверка?
	  	break ;
  }
  while (buf[fd][i] != '\n' && buf[fd][i] != '\0')
  {
	  len++;
	  i++;
  } /* len - индекс символа, который \n */
  printf("%d - это len\n", len);
  printf("%s - вот ета буфер, в который мы считали немножко байтов\n", buf[fd]);
  *line = ft_strsub(buf[fd], 0, len);
  printf("%s - вот ета line\n", *line);
  tmp_buf = ft_strdup(buf[fd] + len + 1);
  free(buf[fd]);
  buf[fd] = tmp_buf;
  printf("%s вот эта буф после \n", buf[fd]);
  return (1); // line has been read
}

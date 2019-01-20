/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/18 19:08:18 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		get_next_line(const int fd, char **line)
{
  char buf[BUFF_SIZE + 1];
  static char *new_buf = "";
  static char new_buf_2[1024];
  int ret;
  int len = 0;
  int i = 0;
  ret = 1;
  while ((ret = read(fd, buf, BUFF_SIZE)))
  {
	  buf[ret] = '\0';
	  if (ret == -1)
	  {
		  printf("OH NO! Terrible mistake. Read() exited with code -1\n");
		  return (-1);
	  }
	  if (ret == 0)
	  {
		  printf("Файл закончился\n");
		  return (0);
	  }
	  new_buf = ft_strjoin(new_buf, buf);// здесь все падает в сегфолт, если не иницализировать new_buf;
  }
  printf("!!!! %s - это - буфер, в который мы считали весь файл!!!!\n", new_buf);
  while (new_buf[i] != '\n')
  {
	  len++;
	  i++;
  }
  printf("%d - это len\n", len);
  ft_strncpy(new_buf_2, new_buf, len); // not sure about ft_strncpy though
  printf("%s - вот ета new_buf_2\n", new_buf_2);// Was *line += len;
  *line = new_buf_2;
  printf("%s - вот ета line\n", *line);
  return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	fd = 0;
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			return (-1);
			printf("О нет! Произошло непоправимое\n");
		}
		get_next_line(fd, &line);
	}
	return (0);
}

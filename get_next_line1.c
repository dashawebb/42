/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/16 21:04:37 by creek            ###   ########.fr       */
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

int		ft_display_line(const int fd, char **line)
{
  static char buf[BUFF_SIZE + 1];
  static char new_buf[BUFF_SIZE + 1];
  static char new_buf_2[BUFF_SIZE + 1];
  int ret;
  // int len;
  // int len1 = 0;
  int j;
  int i = 0;
  j = 0;
  ret = 1;
  while ((ret = read(fd, buf, BUFF_SIZE)))
  {
	  //printf("%lu", read(fd, buf, BUFF_SIZE));
	  printf("%d - ето рет\n", ret);
	  printf("%s - ето буф\n", buf);
	  if (ret == -1)
	  {
		  printf("OH NO! Terrible mistake. Read () exited with code -1\n");
		  return (-1);
	  }
	  if (ret == 0)
	  {
		  printf("Файл закончился\n");
		  return (0);
	  }
	  // len = 0;
  	  // while (buf[j]) // в new_buf здесь записывается только выводимая часть строки
  	  // {
  		//   len++;
  		//   j++;
  	  // }
	  ft_strcat(new_buf, buf);
	 //  j += 1; // потому что надо скипнуть /n
	 //  while (buf[j]) // в new_buf здесь записывается только выводимая часть строки
	 //  {
		//  len1++;
		//  j++;
	 // }
	 // ft_strncpy(new_buf_2, buf, len1);
	 //  *line = &new_buf[0]; // line теперь содержит только строку до \n
	 // buf[BUFF_SIZE - 1] = '\0';
 }

	  // printf("%s - это - считанная линия\n", *line);
	  // printf("%s - это - изначальный буфер\n", &buf[0]); // в буф произошло все считывание. Надо удалить первую часть?
	printf("%s - это - буфер, в который мы считали весь файл\n", new_buf);
	while (new_buf[i] != '\n') // i++
		{
			new_buf_2[i] = new_buf[i];
			i++;
		}
	*line = buf; // placeholder line - rm. Was *line += len;
	//	printf("%s - это - line после обновления\n", *line);
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
		ft_display_line(fd, &line);
		// ft_display_line(fd, &line);
		// ft_display_line(fd, &line);
		// ft_display_line(fd, &line);
	}
	return (0);
}

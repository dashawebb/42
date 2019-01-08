/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line-2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/08 22:45:38 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		ft_display_line(const int fd, char **line)
{
  static char buf[BUFF_SIZE + 1];
  int ret;
  int i;
  int j;

  i = 0;
  j = 0;
  ret = 1;
  while (ret) // до тех пор, пока read не вернет 0. Отдельно обработать ошибку (ret = -1)
  {
	  ret = read(fd, buf, BUFF_SIZE); // в ret передается результат выполнения ф-ии read - кол-во считанных байт
	  /*дальше надо считать все до \n в line, а в buf оставить оставшууюся часть файла */
	  if (ret == 0) // < BUFF_SIZE) // значит это конец файла.! но надо все равно оставшуюся часть записать. Ret меньше BUFF_SIZE может быть во многих случаях. БАФФ_сайз может быть равен 9999999, а сам файл - всего 15 символов
		  return (0);
	  if (ret == -1)
		  return (-1); // в какой-то момент считывание не удалось, значит мы выходим из ф-ии?*/
      printf("%s - это - линия до\n", *line);
	  while (buf[j] != '\n')
	  {
		  // *line = &buf[j];
		  *line[i] = buf[j];
		  i++;
		  j++;
	  }
	  printf("%s - это - считанная линия", line[0]);

//	  buf[BUFF_SIZE - 1] = '\0';
  }
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
		ft_display_line(fd, &line);
	}
	return (0);
}

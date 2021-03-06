/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:31:43 by creek             #+#    #+#             */
/*   Updated: 2019/01/18 19:09:05 by creek            ###   ########.fr       */
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
  int len;
  int len1 = 0;
  int j;

  j = 0;
  ret = 1;
  while (ret) // до тех пор, пока read не вернет 0. Отдельно обработать ошибку (ret = -1)
  {
	  ret = read(fd, buf, BUFF_SIZE); // в ret передается результат выполнения ф-ии read - кол-во считанных байт
	  if (ret == 0) // < BUFF_SIZE) // значит это конец файла! но надо все равно оставшуюся часть записать. Ret меньше BUFF_SIZE может быть во многих случаях. БАФФ_сайз может быть равен 9999999, а сам файл - всего 15 символов
		  return (0);
	  if (ret == -1)
		  return (-1); // в какой-то момент считывание не удалось, значит мы выходим из ф-ии?*/
	len = 0;
	  while (buf[j] != '\n') // в new_buf здесь записывается только выводимая часть строки
	  {
		  len++;
		  j++;
	  }
	  ft_strncpy(new_buf, buf, len);
	  j += 1; // потому что надо скипнуть /n
	  while (buf[j]) // в new_buf здесь записывается только выводимая часть строки
	  {
		 len1++;
		 j++;
	 }
	 ft_strncpy(new_buf_2, buf, len1);
	  *line = &new_buf[0]; // line теперь содержит только строку до \n
	  printf("%s - это - считанная линия\n", *line);
	  printf("%s - это - изначальный буфер\n", &buf[0]); // в буф произошло все считывание. Надо удалить первую часть?
	  printf("%s - это - буфер для записи остатка\n", &new_buf_2[0]);
//	  buf[BUFF_SIZE - 1] = '\0';
		*line += len;
		printf("%s - это - line после обновления\n", *line);

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
		ft_display_line(fd, &line);
		ft_display_line(fd, &line);
		ft_display_line(fd, &line);
	}
	return (0);
}

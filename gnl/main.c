/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:54:00 by creek             #+#    #+#             */
/*   Updated: 2019/01/24 21:53:37 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		printf("%d\n", get_next_line(fd, &line));
		printf("%s --- vot eta Line\n", line);
		printf("%d\n", get_next_line(fd, &line));
		printf("%s --- vot eta Line\n", line);
		printf("%d\n", get_next_line(fd, &line));
		printf("%s --- vot eta Line\n", line);
		printf("%d\n", get_next_line(fd, &line));
		printf("%s --- vot eta Line\n", line);
		printf("%d\n", get_next_line(fd, &line));
		printf("%s --- vot eta Line\n", line);
		printf("%d\n", get_next_line(fd, &line));
		// get_next_line(fd, &line);
		// get_next_line(fd, &line);
		// get_next_line(fd, &line);
		// get_next_line(fd, &line);
		// get_next_line(fd, &line);
	}
	return (0);
}

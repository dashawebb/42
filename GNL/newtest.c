/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:29:38 by creek             #+#    #+#             */
/*   Updated: 2019/01/16 15:51:56 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_display_line(const int fd, char **line)
{
	char str[] = "teststring";
	char *str1 = "heheh";
	char *str2;
    printf("%s - str\n", str);
    printf("%s - str1\n", str1);
    printf("%s - str2\n", str2);
	str2 = str1;
	str1 = str;
	printf("%s - str\n", str);
	printf("%s - str1\n", str1);
	printf("%s - str2\n", str2);
	strcpy(str, "newstring");
    printf("%s - str\n", str);
    printf("%s - str1\n", str1);
	printf("%s - str2\n", str2);
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

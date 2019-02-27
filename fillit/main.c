/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 21:45:07 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/27 12:49:05 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		usage(void)
{
	write(1, "usage: ./fillit <FILE>\n", 23);
	exit(0);
}

void		it_is_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

int			main(int argc, char **argv)
{
	int		quantity;
	t_list	*tetris;
	int		fd;
	char	**map;

	if (argc != 2)
		usage();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tetris = read_tetris(fd);
		quantity = ft_listlen(tetris);
		if (quantity > 26)
			it_is_error();
		fillit(quantity, tetris);
		free_list(tetris);
	}
	return (0);
}

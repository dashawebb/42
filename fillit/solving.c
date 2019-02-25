/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:41:43 by creek             #+#    #+#             */
/*   Updated: 2019/02/22 23:18:26 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_round_up(int nb)
{
	int i;

	i = 0;
	while ((i * i) <= nb)
	{
		if ((i * i) == nb)
			return (i);
		i++;
	}
	return (i++);
}

void	empty_map_drawing(char **map, int map_size)
{
	int i;

	i = 0;
	while (i < map_size)
	{
		map[i] = ft_strnew((size_t)map_size + 1);
		ft_memset(map[i], '.', (size_t)map_size);
		i++;
	}
}

int		solving(int quantity, t_list *tetris, char **map, int map_size)
{
	int yx[2];

	if (quantity == 0)
		return (1);
	yx[0] = 0;
	while (yx[0] < map_size)
	{
		yx[1] = -1;
		while (++yx[1] < map_size)
		{
			if (tetri_placing((t_tetr *)tetris->content, yx, map, map_size))
			{
				tetri_drawing(yx, map, (t_tetr *)tetris->content, map_size);
				quantity--;
				if (solving(quantity, tetris->next, map, map_size))
					return (1);
				remove_tetri((t_tetr *)tetris->content, map, map_size);
				quantity++;
			}
		}
		yx[0]++;
	}
	return (0);
}

char	**fillit(int quantity, t_list *tetris)
{
	int		map_size;
	char	**map;

	map_size = ft_sqrt_round_up(quantity * 4);
	if (!(map = (char **)malloc((sizeof(*map) * (map_size + 1)))))
		return (0);
	empty_map_drawing(map, map_size);
	while (!(solving(quantity, tetris, map, map_size)))
	{
		free(map);
		map_size++;
		if (!(map = (char **)malloc((sizeof(*map) * (map_size + 1)))))
			return (0);
		empty_map_drawing(map, map_size);
	}
	return (map);
}

int		left_corner_check(t_tetr *tetri, int *yx)
{
	int k;

	k = 0;
	if ((tetri->shape)[0][0] == '.' && k == 0 && yx[1] != 0)
	{
		k++;
		if ((tetri->shape[0][2] == tetri->letter) &&
			(tetri->shape[1][0] == tetri->letter) &&
			(tetri->shape[1][1] == tetri->letter) &&
			(tetri->shape[1][2] == tetri->letter))
			k++;
	}
	return (k);
}

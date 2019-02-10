/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:41:43 by creek             #+#    #+#             */
/*   Updated: 2019/02/08 22:10:22 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solving.h"

/* quantity передается от Сашеньки */

int ft_sqrt(int nb)
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

void empty_map_drawing(char **map, int min_size)
{
	int i;

	i = 0;
	while(i < min_size)
	{
		ft_bzero(map[i], (size_t)min_size);
		i++;
	}
}

int map(int quantity)
{
	int map_size;
	char **map;

	map_size = ft_sqrt(quantity * 4);
	if (!(map = (char **)malloc(sizeof(char *) * (map_size * map_size))))
		return (0);
	empty_map_drawing(map, map_size);
	while (!(fitting(map, tetri, map_size, quantity))
	{
		free(map);
		map_size++;
		if (!(map = (char **)malloc(sizeof(char *) * (map_size * map_size))))
			return (0);
		empty_map_drawing(map, map_size);
	}
	return (0);
}

int fitting(char **map, t_tetr **tetri, int map_size, int quantity)/* или t_tetr **tetri */
{
	int i;
	int j; // нужны ли мне тут эти переменные или хуй с ними?
	int quantity_1;

	quantity_1 = quantity;
	if (quantity == 0)
		return (1);
	while (map_iterating(tetri, map, map_size)) // если текущая фигура встает успешно
	{
		tetri_drawing(x, y, map, tetri->shape, tetri->letter); // какие координаты ей передаются?
		quantity--;
		return(fitting(map, tetri->next, map_size, quantity));
	}
	if (quantity == quantity_1) // сюда заходим если map_iterating вернул 0, т.е. фигура не вписалась, и это самая первая фигура, значит надо увеличить карту
	{
		map_size++;
		return(fitting(map, tetri, map_size, quantity));
	}
	return (0); // сюда заходим, если map_iterating вернул 0, и это любая другая фигура - выход из рекурсии
}

int map_iterating(t_tetr **tetri, char **map, int map_size)
{
	int i;
	int j; // координаты фигуры тетримины
	int x;
	int y; // координаты точки на карте

	j = 0;
	while (y + j < map_size)
	{
		i = 0;
		x = 0;
		while (x + i < map_size)
		{
			if (map[y + j][x + i] == '\0')
				i++; // i должно итерироваться только до тех пор, пока оно < width, то же с j;
			else if ((map[y + j][x + i] != '\0') && (tetri->shape[j][i] != '.'))
			{
				i = 0; // если в точке тетри есть символ, а места для него нет, мы продолжаем поиск
				j = 0;
				x++;
			}
			if((j == tetri->height - 1) && (i == tetri->width - 1))
				return (1); // фигура вписалась
			x++;
		}
		y++;
	}
	return (0);
}

int tetri_drawing(size_t x, size_t y, char **map, char **shape)//, char letter)
{
	size_t i;
	size_t j;

	j = 0;
	while (shape[j])
	{
		y += j;
		i = 0;
		while (shape[j][i])
		{
			x += i;
			if (shape[j][i] != '.')
				map[y][x] = shape[j][i];
			i++;
		}
		j++;
	}
	return (1); //что мне надо вернуть?
}

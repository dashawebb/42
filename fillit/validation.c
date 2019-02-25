/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:02:40 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/12 19:18:18 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_size(char **tetr)
{
	int	x;
	int	y;
	int	size;

	y = 0;
	size = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			if (tetr[y][x] == '#')
				size++;
			x++;
		}
		y++;
	}
	return (size);
}

int		check_link(char **tetr, int x, int y)
{
	int	link;

	link = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			if (tetr[y][x] == '#')
			{
				if ((x < 4) && (tetr[y][x + 1] == '#'))
					link++;
				if ((x > 0) && (tetr[y][x - 1] == '#'))
					link++;
				if ((y < 3) && (tetr[y + 1][x] == '#'))
					link++;
				if ((y > 0) && (tetr[y - 1][x] == '#'))
					link++;
			}
			x++;
		}
		y++;
	}
	return (link);
}

int		check_points(char **tetr)
{
	int	x;
	int	y;
	int	points;

	y = 0;
	points = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			if (tetr[y][x] == '#' || tetr[y][x] == '.')
				points++;
			x++;
		}
		y++;
	}
	return (points);
}

int		check_newline(char **tetr)
{
	int	x;
	int	y;
	int	newline;

	y = 0;
	while (tetr[y])
	{
		x = 0;
		newline = 0;
		while (x < 5)
		{
			if (tetr[y][x] == '\n')
				newline++;
			x++;
		}
		if (newline > 1)
			return (1);
		y++;
	}
	return (0);
}

void	valid_check(char **tetr)
{
	if ((check_points(tetr) != 16) || (check_size(tetr) != 4)
		|| ((check_link(tetr, 0, 0) != 6) && (check_link(tetr, 0, 0) != 8))
		|| (check_newline(tetr) == 1))
		it_is_error();
}

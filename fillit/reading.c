/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:56:24 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/22 23:11:19 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		to_letters(char **tetr, char letter)
{
	int		i;
	int		j;

	i = 0;
	while (tetr[i] != NULL)
	{
		j = 0;
		while (tetr[i][j] != '\0')
		{
			if (tetr[i][j] == '#')
				tetr[i][j] = letter;
			j++;
		}
		i++;
	}
}

char		**create_shape(char *buff, char letter)
{
	char	**temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!(temp = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	temp[4] = NULL;
	while (i < 4)
	{
		if (!(temp[i] = (char*)malloc(5)))
			return (NULL);
		j = 0;
		while (j < 4)
			temp[i][j++] = buff[k++];
		temp[i++][j] = '\0';
		k++;
	}
	valid_check(temp);
	to_letters(temp, letter);
	return (temp);
}

t_list		*create_tetr(char *b, char letter)
{
	int		a[3];
	t_tetr	tetr;

	init_vars(a);
	while (b[++a[2]] != '\0')
	{
		if (b[a[2]] == '#')
		{
			if (b[a[2] + 1] == '#' && b[a[2] + 5] == '#' && b[a[2] + 6] == '#')
			{
				a[0] = 2;
				a[1] = 2;
				break ;
			}
			if ((a[2] < 19) && (b[a[2] + 1] == '#'))
				a[1]++;
			if ((a[2] < 14) && (b[a[2] + 5] == '#'))
				a[0]++;
		}
	}
	tetr.height = a[0];
	tetr.width = a[1];
	tetr.letter = letter;
	tetr.shape = create_shape(b, letter);
	return (ft_lstnew(&tetr, sizeof(t_tetr)));
}

t_list		*read_tetris(int fd)
{
	int		ret;
	char	letter;
	char	buff[22];
	t_list	*tetris;
	t_list	*tetr;

	if (fd < 0)
		it_is_error();
	tetris = NULL;
	letter = 'A';
	while ((ret = read(fd, buff, 21)) && (ret != -1))
	{
		buff[ret] = '\0';
		if ((ret != 21) && (buff[ret - 2] == '\n'))
			it_is_error();
		tetr = create_tetr(buff, letter++);
		if (tetr == NULL)
			free_list(tetris);
		ft_listadd_to_end(&tetris, tetr);
	}
	if (ret == -1 || tetris == NULL || buff[20] == '\n')
		it_is_error();
	return (tetris);
}

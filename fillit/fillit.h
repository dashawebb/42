/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:20:03 by elchrist          #+#    #+#             */
/*   Updated: 2019/02/25 21:30:07 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define malloc(x) malloc(-1)
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
typedef struct	s_tetr
{
	int			height;
	int			width;
	char		**shape;
	char		letter;
}				t_tetr;

char			**create_shape(char *buff, char letter);
char			**fillit(int quantity, t_list *tetris);

t_list			*create_tetr(char *buff, char letter);
t_list			*read_tetris(int fd);

void			it_is_error(void);
void			valid_check(char **tetr);
void			to_letters(char **tetr, char letter);
void			free_list(t_list *head);
void			ft_listadd_to_end(t_list **begin_list, t_list *new);
void			print_list(t_list *list);
void			printing_fin_map(char **map);
void			empty_map_drawing(char **map, int map_size);
void			cut_empty_lines(t_tetr *tetri);
void			cut_empty_column(t_tetr *tetri);
void			init_vars(int *arr);

int				tetri_placing(t_tetr *tetri, int *yx, char **map, int map_size);
int				left_corner_check(t_tetr *tetri, int *yx);
int				remove_tetri(t_tetr *tetri, char **map, int map_size);
int				tetri_drawing(int *yx, char **map, t_tetr *tetri, int map_size);
int				solving(int quantity, t_list *tetris, char **map, int map_size);
int				ft_listlen(t_list *content);
int				check_size(char **tetr);
int				check_link(char **tetr, int x, int y);
int				check_points(char **tetr);
int				check_newline(char **tetr);
int				ft_sqrt_round_up(int nb);

#endif

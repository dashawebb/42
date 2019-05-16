/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:36:57 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 16:57:07 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Functions for parse argumetns, and fill flags/"queue"
*/

static void		parse_flags(char *arg)
{
	arg++;
	while (*arg)
	{
		if (!ft_strchr("1ARUTacfgloprtxu", *arg))
			handle_error(E_ILL_OPT, &(*arg));
		fill_fflags(*arg);
		fill_sflags(*arg);
		fill_tflags(*arg);
		arg++;
	}
}

void			init_flags(void)
{
	if (!(g_flags = (t_flags *)malloc(sizeof(t_flags))))
		handle_error(E_MLLC_CRSH, NULL);
	g_flags->l = 0;
	g_flags->y = 0;
	g_flags->a = 0;
	g_flags->r = 0;
	g_flags->t = 0;
	g_flags->one = 0;
	g_flags->b_a = 0;
	g_flags->b_t = 0;
	g_flags->x = 0;
	g_flags->f = 0;
	g_flags->u = 0;
	g_flags->c = 0;
	g_flags->g = 0;
	g_flags->b_u = 0;
	g_flags->p = 0;
	g_flags->o = 0;
}

t_rbtree		*parse_args(int ac, char **av)
{
	t_rbtree	*queue;
	int			flag;
	int			i;

	i = 1;
	flag = 0;
	queue = NULL;
	while (i < ac)
	{
		if (!flag && av[i][0] == '-')
			parse_flags(av[i]);
		else
		{
			flag = 1;
			if (!select_queue_sort(&queue, ft_rbtnew(av[i], \
										ft_strlen(av[i]) + 1)))
				handle_error(E_MLLC_CRSH, NULL);
		}
		i++;
	}
	if (!flag && !select_queue_sort(&queue, ft_rbtnew(".", 2)))
		handle_error(E_MLLC_CRSH, NULL);
	return (queue);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:34:08 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/21 17:11:05 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Main calls function that parse argumets and fill flags. "queue" is a
** red-black tree with folders to read and display. If no argumetns passed,
** queue stores only current directory ".".
**
** "render" handles "queue" and pass to "read_dir" each tree's element. This
** function necessary for -R flag and recursive reading folders.
*/

void	render(t_rbtree *queue)
{
	ft_rbtforeach(queue, read_dir, INFIX);
	ft_rbtclr(&queue, del_queue);
}

int		main(int ac, char **av)
{
	t_rbtree	*queue;

	init_flags();
	queue = parse_args(ac, av);
	if (!isatty(STDOUT_FILENO) && !g_flags->l)
		g_flags->one = 1;
	g_info = NULL;
	render(queue);
	free(g_flags);
	return (EXIT_SUCCESS);
}

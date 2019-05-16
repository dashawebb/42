/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 15:47:26 by trhogoro          #+#    #+#             */
/*   Updated: 2018/12/22 15:47:49 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	handle_error(unsigned int i, char *arg)
{
	if (i == E_ILL_OPT)
	{
		write(1, "ft_ls: illegal option -- ", 25);
		write(1, &(arg[1]), 1);
		write(1, "\n", 1);
		write(1, "usage: ls [-1ARUTacfgloprtxu] [file ...]", 30);
		write(1, "\n", 1);
	}
	if (i == E_MLLC_CRSH)
		write(1, "ft_ls: malloc crashed\n", 21);
	exit(EXIT_FAILURE);
}

int		handle_errno(char *arg)
{
	char	*buf;

	buf = strerror(errno);
	write(2, "ft_ls: ", 7);
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, buf, ft_strlen(buf));
	write(2, "\n", 1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkertzma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:30:59 by nkertzma          #+#    #+#             */
/*   Updated: 2018/12/22 16:57:25 by nkertzma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		fill_tflags(char c)
{
	if (c == 'c')
		g_flags->c = 1;
	else if (c == 'g')
	{
		g_flags->g = 1;
		g_flags->l = 1;
	}
	else if (c == 'U')
		g_flags->b_u = 1;
	else if (c == 'p')
		g_flags->p = 1;
	else if (c == 'o')
		g_flags->o = 1;
	else
		return (0);
	return (1);
}

int		fill_sflags(char c)
{
	if (c == 'A')
		g_flags->b_a = 1;
	else if (c == 'T')
		g_flags->b_t = 1;
	else if (c == 'x')
	{
		g_flags->x = 1;
		g_flags->l = 0;
		g_flags->one = 0;
	}
	else if (c == 'f')
	{
		g_flags->f = 1;
		g_flags->a = 1;
	}
	else if (c == 'u')
		g_flags->u = 1;
	else
		return (0);
	return (1);
}

int		fill_fflags(char c)
{
	if (c == 'l')
	{
		g_flags->l = 1;
		g_flags->one = 0;
	}
	else if (c == 'R')
		g_flags->y = 1;
	else if (c == 'a')
		g_flags->a = 1;
	else if (c == 'r')
		g_flags->r = 1;
	else if (c == 't')
		g_flags->t = 1;
	else if (c == '1')
	{
		g_flags->one = 1;
		g_flags->l = 0;
	}
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:13:24 by creek             #+#    #+#             */
/*   Updated: 2018/12/06 17:44:10 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char *d;
	unsigned char m;

	d = (unsigned char*)s;
	m = (char)n;
	if (n != 0)
	{
		while (n > 0)
		{
			*d = 0;
			d++;
			n--;
		}
	}
}

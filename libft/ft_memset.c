/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:50:51 by creek             #+#    #+#             */
/*   Updated: 2018/11/25 22:55:52 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *d;
	unsigned char p;

	d = b;
	p = c;
	while (len > 0)
	{
		*d = p;
		d++;
		len--;
	}
	return (b);
}
/*	unsigned char *dst = b;
	while (len > 0) {
	*dst = (unsigned char) c;
	dst++;
	len--;
	}
	return b;
}*/

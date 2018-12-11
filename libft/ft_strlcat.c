/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:02:30 by creek             #+#    #+#             */
/*   Updated: 2018/12/06 17:50:19 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*d;
	char			*s;
	size_t			n;
	size_t			d_len;

	d = dst;
	s = (char*)src;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	d_len = d - dst;
	n = size - d_len;
	if (n == 0)
		return (d_len + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (d_len + (s - src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:02:30 by creek             #+#    #+#             */
/*   Updated: 2018/12/01 19:17:11 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
// надо написать strlen?
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
/*	int i;
	int j;
	
	i = 0;
	j = 0;
	
	while (dst[j])
		j++;
	while (src[i] && i < size)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (dst);
	}*/
	char *d = dst;
	const char *s = src;
	size_t n = size;
	size_t d_len;
	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	d_len = d - dst;
	n = size - d_len;
	if (n == 0)
		return(d_len + strlen(s));
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
	return(d_len + (s - src));
}

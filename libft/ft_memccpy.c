/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:49:06 by creek             #+#    #+#             */
/*   Updated: 2018/11/26 17:07:12 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
    char *new_dst;
    char *new_src;
	unsigned char new_c;

    new_dst = (char *)dst;
    new_src = (char *)src;
	new_c = (unsigned char)c;
    while (n > 0 && *new_src != new_c)
    {
        *new_dst = *new_src;
        new_dst++;
		new_src++;
		n--;
    }
	if (*new_src == new_c)
		return (++new_dst);
    else
		return (NULL);
}


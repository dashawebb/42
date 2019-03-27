/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:49:06 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 21:33:03 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	unsigned char	new_c;

	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	new_c = (unsigned char)c;
	while (n > 0)
	{
		*new_dst = *new_src;
		if (*new_src == new_c)
			return (new_dst + 1);
		new_dst++;
		new_src++;
		n--;
	}
	return (NULL);
}

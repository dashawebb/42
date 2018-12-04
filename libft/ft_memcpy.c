/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:01:30 by creek             #+#    #+#             */
/*   Updated: 2018/11/26 15:48:38 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int i;
	char *new_dst;
	char *new_src;

	i = 0;
	new_dst = (char *) dst;
	new_src = (char *) src;
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (new_dst);
}

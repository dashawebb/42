/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:33:09 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 21:29:11 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*new_dst;
	char	*new_src;
	size_t	i;

	new_dst = (char *)dst;
	new_src = (char *)src;
	i = 0;
	if (new_src > new_dst)
	{
		while (i < len)
		{
			new_dst[i] = new_src[i];
			i++;
		}
	}
	if (new_src < new_dst)
	{
		while (len > 0)
		{
			new_dst[len - 1] = new_src[len - 1];
			len--;
		}
	}
	return (dst);
}

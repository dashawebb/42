/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:05:24 by creek             #+#    #+#             */
/*   Updated: 2018/12/11 15:54:48 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (*src != '\0')
		{
			dst[i] = *src;
			src++;
		}
		else
		{
			dst[i] = '\0';
		}
		i++;
	}
	return (dst);
}

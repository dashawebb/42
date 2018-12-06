/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:05:24 by creek             #+#    #+#             */
/*   Updated: 2018/12/06 20:07:30 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	while (len > 0)
	{
		while (*src != '\0')
		{
			*dst = *src;
			dst++;
			src++;
			len--;
		}
		*dst = '\0';
		dst++;
		len--;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:00:20 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/07 19:54:39 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (len > 0 && *a != (unsigned char)c)
	{
		len--;
		a++;
	}
	if (len == 0)
		return (NULL);
	else
		return (a);
}

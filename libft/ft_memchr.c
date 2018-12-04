/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:47:45 by creek             #+#    #+#             */
/*   Updated: 2018/11/26 19:05:19 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *new_s;
	unsigned char new_c;

	new_s = (char *)s;
	new_c = (unsigned char)c;
	while (n > 0)
	{
		if (*new_s == new_c)
			return (new_s);
		else
			new_s++;
		n--;
	}
	return (NULL);
}

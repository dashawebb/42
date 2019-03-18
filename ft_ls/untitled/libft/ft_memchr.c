/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:47:45 by creek             #+#    #+#             */
/*   Updated: 2018/12/11 15:54:04 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_s;
	unsigned char	new_c;

	new_s = (unsigned char *)s;
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

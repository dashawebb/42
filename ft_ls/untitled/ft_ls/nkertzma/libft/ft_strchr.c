/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trhogoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:59:26 by trhogoro          #+#    #+#             */
/*   Updated: 2018/11/20 05:43:12 by trhogoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char byte;

	byte = (char)(c % 256);
	while (*s != byte)
		if (!*s++)
			return (0x0);
	return ((char *)s);
}

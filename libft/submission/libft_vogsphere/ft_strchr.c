/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:18:05 by creek             #+#    #+#             */
/*   Updated: 2018/12/11 14:02:57 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char c1;
	char *s1;

	s1 = (char *)s;
	c1 = (char)c;
	if (*s1 == c1)
		return (s1);
	while (*s1++ != '\0')
	{
		if (*s1 == c1)
		{
			return (s1);
			break ;
		}
	}
	return (NULL);
}

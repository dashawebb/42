/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:18:05 by creek             #+#    #+#             */
/*   Updated: 2018/12/15 18:19:31 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char c1;
	char *s1;
	char *s2;

	s1 = (char *)s;
	s2 = 0;
	c1 = (char)c;
	if (*s1 == c1)
		s2 = s1;
	while (*s1++ != '\0')
	{
		if (*s1 == c1)
			s2 = s1;
	}
	return (s2 != 0 ? s2 : NULL);
}

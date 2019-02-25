/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:33:17 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/03 20:41:21 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	size_t		len;
	const char	*s1;

	s1 = s;
	i = 0;
	len = ft_strlen(s1);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (s[i])
	{
		if (s[i] != (char)c)
			i++;
		else
			return ((char *)s + i);
	}
	return (NULL);
}

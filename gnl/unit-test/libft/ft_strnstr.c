/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:03:55 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 21:00:18 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	size_t	len2;
	char	*haystack1;

	i = 0;
	len2 = ft_strlen(needle);
	haystack1 = (char *)haystack;
	if (!(*needle))
		return (haystack1);
	while (haystack1[i] && (len > 0) && (len >= len2))
	{
		j = 0;
		while (haystack1[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (haystack1 + i);
			j++;
		}
		i++;
		len--;
	}
	return (NULL);
}

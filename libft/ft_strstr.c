/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:14:05 by creek             #+#    #+#             */
/*   Updated: 2018/12/11 15:57:43 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*haystack1;

	i = 0;
	haystack1 = (char *)haystack;
	if (!(*needle))
		return (haystack1);
	while (haystack1[i])
	{
		j = 0;
		while (haystack1[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (haystack1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

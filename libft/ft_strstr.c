/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:14:05 by creek             #+#    #+#             */
/*   Updated: 2018/12/04 16:01:26 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *ptr;
	int i;

	i = 0;
	if ((!(*haystack)) && (!(*needle))) 
		return (NULL);
	while (*haystack)
	{
		i = 0;
		ptr = (char *)haystack;
		while (needle[i] && (*haystack == needle[i]))
		{
			haystack++;
			i++;
		}
		if (needle[i] == '\0')
			return (ptr);
		haystack++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:03:55 by creek             #+#    #+#             */
/*   Updated: 2018/12/06 14:58:15 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if ((!(*haystack)) && (!(*needle)))
		return (NULL);
	while (*haystack && (len > 0))
	{
		i = 0;
		ptr = (char *)haystack;
		while (needle[i] && (*haystack == needle[i]))
		{
			haystack++;
			i++;
			len--;
		}
		if (needle[i] == '\0')
			return (ptr);
		haystack++;
		len--;
	}
	return (NULL);
}

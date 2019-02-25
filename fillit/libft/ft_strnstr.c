/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:07:32 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/10 19:20:35 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)(haystack + i));
	while (haystack[i] && i < len)
	{
		if (needle[j] && (haystack[i] == needle[j]) && (i < len))
		{
			i++;
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i - j));
	}
	return (NULL);
}

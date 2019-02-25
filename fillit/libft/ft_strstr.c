/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:09:24 by elchrist          #+#    #+#             */
/*   Updated: 2018/11/30 22:38:32 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int haystack_i;
	int needle_i;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		haystack_i = i;
		needle_i = 0;
		while (haystack[haystack_i] == needle[needle_i] && needle[needle_i])
		{
			haystack_i++;
			needle_i++;
		}
		if (needle[needle_i] == '\0' && needle_i > 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

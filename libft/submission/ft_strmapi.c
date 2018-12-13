/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:20:54 by creek             #+#    #+#             */
/*   Updated: 2018/12/13 20:36:18 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = (*f)(i, *s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

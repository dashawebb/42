/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:52:33 by creek             #+#    #+#             */
/*   Updated: 2018/12/13 20:34:59 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		str[i] = (*f)(*s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

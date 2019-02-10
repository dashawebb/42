/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:01:38 by creek             #+#    #+#             */
/*   Updated: 2019/01/18 17:24:58 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_str = (char*)malloc(sizeof(*new_str) * (len + 1))))
		return (NULL);
	while (s1[j])
	{
		new_str[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		new_str[i + j] = s2[i];
		i++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

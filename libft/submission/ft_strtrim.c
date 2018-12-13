/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:14:43 by creek             #+#    #+#             */
/*   Updated: 2018/12/13 20:37:43 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	int		start;
	int		i;
	int		len;

	start = -1;
	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[++start] == ' ' || s[start] == '\n' || s[start] == '\t')
		len--;
	if (len <= 0)
		len = 0;
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	while (i <= len)
	{
		new_str[i++] = s[start];
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

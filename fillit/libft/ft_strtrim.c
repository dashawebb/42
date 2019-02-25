/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:59:31 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/07 22:58:16 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		len;
	char		*s1;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (i < len && ft_space(s[i]))
		i++;
	while (len > i && ft_space(s[len]))
		len--;
	if (i == len)
		return (ft_strnew(1));
	s1 = ft_strsub(s, i, len - i + 1);
	return (s1);
}

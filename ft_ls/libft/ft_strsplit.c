/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:49:14 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 21:54:00 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_word(const char *str, int i, char **ret, char c)
{
	int		len;
	int		space;

	space = 0;
	len = 0;
	while (*str == c)
	{
		str++;
		space++;
	}
	while (str[len] && str[len] != c)
		len++;
	if (len > 0)
	{
		if (!(ret[i] = ft_strnew(len)))
			return (0);
		ft_strncpy(ret[i], str, len);
	}
	return (space + len);
}

static int		count_words(const char *str, int i, char c)
{
	while (*str == c)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str == c)
			str++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	char	**ret;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, 0, c);
	len = 0;
	if (!(ret = (char **)ft_memalloc((count + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	len = 0;
	while (*s)
	{
		if ((len = find_word(s, i++, ret, c)) == 0)
		{
			free(ret);
			return (NULL);
		}
		s += len;
	}
	ret[count] = 0;
	return (ret);
}

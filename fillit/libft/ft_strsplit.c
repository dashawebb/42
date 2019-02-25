/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:18:46 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/07 17:53:44 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		cleaning(char **arr, int index)
{
	while (index > 0)
	{
		index--;
		ft_strdel(&arr[index]);
	}
	ft_strdel(arr);
}

static int		count_words(char *s, char sep)
{
	int		i;
	int		quantity;

	quantity = 0;
	i = 0;
	while (s[i] && s[i] == sep)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != sep)
			i++;
		quantity++;
		while (s[i] && s[i] == sep)
			i++;
	}
	return (quantity);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words_counter;
	int		word_index;

	if (s == NULL)
		return (NULL);
	words_counter = count_words((char *)s, c);
	array = (char **)ft_memalloc(sizeof(char *) * (words_counter + 1));
	if (array == NULL)
		return (NULL);
	word_index = 0;
	while (word_index < words_counter)
	{
		s = next_word(s, c);
		array[word_index] = ft_strsub(s, 0, word_len(s, c));
		if (array[word_index] == NULL)
		{
			cleaning(array, word_index);
			return (NULL);
		}
		word_index++;
		s = s + word_len(s, c);
	}
	array[word_index] = NULL;
	return (array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:28:31 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/07 16:30:26 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char *s, char sep)
{
	int	i;
	int	quantity;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:21:42 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/05 22:08:36 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	finding_len(int n)
{
	int		temp;
	int		length;

	length = 0;
	temp = n;
	if (n < 0)
	{
		n = n * -1;
		length = length + 1;
	}
	while (temp)
	{
		temp = temp / 10;
		length = length + 1;
	}
	return (length);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = finding_len(n);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (len != 0)
		str[0] = '-';
	return (str);
}

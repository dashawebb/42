/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:55:59 by creek             #+#    #+#             */
/*   Updated: 2018/12/12 20:29:54 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	reverse(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}

int		ft_int_len(int n)
{
	int len;

	len = 0;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		ft_sign(int n)
{
	int sign;

	sign = 0;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		rem;
	char	*str;
	int		sign;

	i = 0;
	len = ft_int_len(n);
	sign = ft_sign(n);
	if (sign != 0)
		n = -n;
	if (!(str = (char*)malloc((len + 1) * sizeof(*str))))
//	if (!(new_str = (char*)malloc((len + 1) * sizeof(*new_str))))
		return (NULL);
	while (n != 0)
	{
		rem = n % 10;
		str[i++] = rem + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:55:59 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 20:20:08 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static char		*reverse(char *str)
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
	return (str);
}

static	int		ft_int_len(int n)
{
	int len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int		ft_is_neg(int n)
{
	return (1 ? n < 0 : 0);
}

static char		*writing_str(char *str, int n, int sign)
{
	int i;
	int rem;

	i = 0;
	while (n > 0)
	{
		rem = n % 10;
		str[i++] = rem + '0';
		n = n / 10;
	}
	if (sign == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = ft_is_neg(n);
	len = ft_int_len(n) + sign;
	if (sign > 0)
		n = -n;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	writing_str(str, n, sign);
	return (reverse(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:55:59 by creek             #+#    #+#             */
/*   Updated: 2018/12/13 22:13:46 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	len = 1;
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
		sign = -1;
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
	{
		n = -n;
		len += 1;
	}
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (str = ft_strdup(""));
	else
	{
		while (n > 0)
		{
			rem = n % 10;
			str[i++] = rem + '0';
			n = n / 10;
		}
		if (sign == -1)
			str[i++] = '-';
		str[i] = '\0';
		reverse(str);
	}
	return (str);
}

// void	itoa_isnegative(int *n, int *negative)
// {
// 	if (*n < 0)
// 	{
// 		*n *= -1;
// 		*negative = 1;
// 	}
// }
//
// char	*ft_itoa(int n)
// {
// 	int		tmpn;
// 	int		len;
// 	int		negative;
// 	char	*str;
//
// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	tmpn = n;
// 	len = 2;
// 	negative = 0;
// 	itoa_isnegative(&n, &negative);
// 	while (tmpn /= 10)
// 		len++;
// 	len += negative;
// 	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
// 		return (NULL);
// 	str[--len] = '\0';
// 	while (len--)
// 	{
// 		str[len] = n % 10 + '0';
// 		n = n / 10;
// 	}
// 	if (negative)
// 		str[0] = '-';
// 	return (str);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:49:48 by creek             #+#    #+#             */
/*   Updated: 2019/01/15 22:23:03 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	unsigned long long	num;
	int					sign;

	num = 0;
	sign = 1;
	while (*str == '\r' || *str == '\t' || *str == '\n' \
	|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (num > LLONG_MAX)
		return (sign < 0) ? 0 : -1;
	return ((int)num * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:49:48 by creek             #+#    #+#             */
/*   Updated: 2018/12/13 21:43:03 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int num;
	int sign;

	num = 0;
	sign = 1;
	// if (str != NULL)
	// {

		while (*str == '\r' || *str == '\t' || *str == '\n')
			str++;
		while (*str == '\v' || *str == '\f' || *str == ' ')
			str++;
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			sign = -1;
			str++;
		}
		while (*str >= '0' && *str <= '9' && *str != '\0')
		{
			num = num * 10 + *str - '0';
			str++;
		}
		return (num * sign);
	// }
	// return (0);
}

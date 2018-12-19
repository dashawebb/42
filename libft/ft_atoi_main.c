/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:21:07 by creek             #+#    #+#             */
/*   Updated: 2018/12/19 18:21:09 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char *str = "−9223372036854775828";
	char *str1 = "−9223372036854775028";
	char *str2 = "9223372036854775828";
	char *str3 = "9223372036854775808";
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str1));
	printf("%d\n", ft_atoi(str1));
	printf("%d\n", atoi(str2));
	printf("%d\n", ft_atoi(str2));
	printf("%d\n", atoi(str3));
	printf("%d\n", ft_atoi(str3));
}

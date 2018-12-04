/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_main1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:48:53 by creek             #+#    #+#             */
/*   Updated: 2018/12/01 22:58:19 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *ft_strncpy(char *dst, const char *src, size_t len);

int main()
{
    char src2[] = "Irina Istyukova";
    char dst2[100] = "Zhanna";

    printf("%s\n", ft_strncpy(dst2, src2, 0));
	printf("%s", dst2);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:13:12 by creek             #+#    #+#             */
/*   Updated: 2018/12/01 21:34:48 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int		main()
{
	char str1[] = "Helloghjjj";
	char str2[] = "Uebki))))";
	printf("%lu", strlcat(str1, str2, 13));
	printf("\n");
	char str3[100] = "Helloghjjj";
    char str4[] = "Uebki))))";
    printf("%lu\n", ft_strlcat(str3, str4, 13));
/*	printf("%lu\n", sizeof(str1));
    printf("%lu\n", sizeof(str3));
    printf("%lu\n", sizeof(str2));
    printf("%lu\n", sizeof(str4));*/
	printf("%s\n", str1);
	printf("%s\n", str3); 
    return (0);
}

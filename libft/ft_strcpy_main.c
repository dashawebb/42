/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:31:17 by creek             #+#    #+#             */
/*   Updated: 2018/11/28 14:55:01 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strcpy(char *dst, const char *src);

int		main(void)
{
	char str1[] = "U Dani bolshaya golova";
/*	str1 = (char *)malloc(23);
	str1[22] = '\0';
	strcpy(str1, "U Dani bolshaya golova");*/
	char str2[] = "A u Sashi malenkiy";
	printf("str1 before strcpy: %s\nstr2 before strcpy: %s\n", str1, str2);
	strcpy(str1, str2);
	printf("str1 after strcpy: %s\nstr2 after strcpy: %s\n", str1, str2);
	char str3[] = "U Dani bolshaya golova";
    char str4[] = "A u Sashi malenkiy";
    printf("str3 before ft_strcpy: %s\nstr4 before ft_strcpy: %s\n", str3, str4);
    ft_strcpy(str3, str4);
    printf("str3 after ft_strcpy: %s\nstr4 after ft_strcpy: %s\n", str3, str4);
	return (0);
}

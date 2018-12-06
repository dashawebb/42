/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:31:17 by creek             #+#    #+#             */
/*   Updated: 2018/12/06 20:39:55 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strncpy(char *dst, const char *src, size_t len);

int		main(void)
{
	int len;
	len = 10;
	char str1[] = "U Dani bolshaya";
	char *src = "--> nyancat <--\n\r";
	char dst1[30];
	size_t max = 12;
/*	str1 = (char *)malloc(23);
	str1[22] = '\0';
	strcpy(str1, "U Dani bolshaya golova");*/
	char str2[] = "A u Sash";
	printf("str1 before strncpy: %s\nstr2 before strncpy: %s\n", src, dst1);
	strncpy(src, dst1, max);
	printf("str1 after strncpy: %s\nstr2 after strncpy: %s\n", src, dst1);
	char str3[] = "U Dani bolshaya";
    char str4[] = "A u Sash";
	char *src1 = "--> nyancat <--\n\r";
	char dst11[30];
	size_t max1 = 12;
    printf("str1 before ft_strncpy: %s\nstr2 before ft_strncpy: %s\n", src1, dst11);
    ft_strncpy(src1, dst11, max);
    printf("str3 after ft_strncpy: %s\nstr4 after ft_strncpy: %s\n", src1, dst11);
	return (0);
}

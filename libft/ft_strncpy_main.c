/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:31:17 by creek             #+#    #+#             */
/*   Updated: 2018/12/01 22:59:43 by creek            ###   ########.fr       */
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
/*	str1 = (char *)malloc(23);
	str1[22] = '\0';
	strcpy(str1, "U Dani bolshaya golova");*/
	char str2[] = "A u Sash";
	printf("str1 before strncpy: %s\nstr2 before strncpy: %s\n", str1, str2);
	strncpy(str1, str2, 0);
	printf("str1 after strncpy: %s\nstr2 after strncpy: %s\n", str1, str2);
	char str3[] = "U Dani bolshaya";
    char str4[] = "A u Sash";
    printf("str3 before ft_strncpy: %s\nstr4 before ft_strncpy: %s\n", str3, str4);
    ft_strncpy(str3, str4, 0);
    printf("str3 after ft_strncpy: %s\nstr4 after ft_strncpy: %s\n", str3, str4);
	return (0);
}

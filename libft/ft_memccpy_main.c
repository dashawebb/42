/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:04:45 by creek             #+#    #+#             */
/*   Updated: 2018/11/28 15:05:38 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

int main () {
	int c;

	c = '1';
	const char src[54] = "C is a wonderf1ul gift of God, and I genuinely mean it";
	char dest[60] = "C is a wonderf1ul gift of God, and I genuinely mean it";
	strcpy(dest,"Heloooo!!");
	printf("Before memccpy dest = %s\n", dest);
	memccpy(dest, src,  c, strlen(src)+1);
	char *str3 = memccpy(dest, src, c, strlen(src)+1);
    printf("After ft_memccpy dest = %s\n. The next symbol is %s\n", dest, str3);

	const char src1[54] = "C is a wonderful gift of God, and I genuinely mean it";
    strcpy(dest,"Heloooo!!");
    printf("Before ft_memccpy dest = %s\n", dest);
    char *str2 = ft_memccpy(dest, src, c, strlen(src)+1);
    printf("After ft_memccpy dest = %s\n. The next symbol is %s\n", dest, str2);

	return(0);
}
/*
int main () {
	const char src[50] = "http://www.tutorialspoint.com";
	char dest[50];
	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
   
	return(0);
}
*/

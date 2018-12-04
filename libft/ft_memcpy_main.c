/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:04:45 by creek             #+#    #+#             */
/*   Updated: 2018/11/26 16:26:29 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

int main () {
	const char src[60] = "C is a wonderful gift of God, and I genuinely mean it";
	char dest[60];
	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);

	const char src1[60] = "C is a wonderful gift of God, and I genuinely mean it";
    strcpy(dest,"Heloooo!!");
    printf("Before ft_memcpy dest = %s\n", dest);
    ft_memcpy(dest, src1, strlen(src)+1);
    printf("After ft_memcpy dest = %s\n", dest);

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:50:48 by creek             #+#    #+#             */
/*   Updated: 2018/11/26 19:53:13 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);

int main () {
	char str1[15];
	char str2[15];
	int ret;

	memcpy(str1, "abcdef", 6);
	memcpy(str2, "ABCDEF", 6);

	ret = memcmp(str1, str2, 5);

	if(ret > 0) {
		printf("str2 is less than str1");
	} else if(ret < 0) {
		printf("str1 is less than str2");
	} else {
		printf("str1 is equal to str2");
	}
	memcpy(str1, "abcdef", 6);
    memcpy(str2, "ABCDEF", 6);

    ret = ft_memcmp(str1, str2, 5);

    if(ret > 0) {
		printf("str2 is less than str1");
    } else if(ret < 0) {
		printf("str1 is less than str2");
    } else {
		printf("str1 is equal to str2");
    }
	return(0);
}

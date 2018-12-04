/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:13:12 by creek             #+#    #+#             */
/*   Updated: 2018/11/28 19:06:09 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncat(char *s1, const char *s2, size_t n);

int		main()
{
	char str1[20] = "Hello";
	char str2[] = "Uebki))))";
	printf("%s", strncat(str1, str2, 6));
	printf("\n");
	char str3[20] = "Hello";
    char str4[] = "Uebki))))";
    printf("%s", ft_strncat(str3, str4, 6));
    return (0);
}

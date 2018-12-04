/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:13:12 by creek             #+#    #+#             */
/*   Updated: 2018/11/28 16:28:51 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strcat(char *s1, const char *s2);

int		main()
{
	char str1[20] = "Hello";
	char str2[] = "Uebki))))";
	printf("%s", strcat(str1, str2));
	printf("\n");
	char str3[20] = "Hello";
    char str4[] = "Uebki))))";
    printf("%s", ft_strcat(str3, str4));
    return (0);
}

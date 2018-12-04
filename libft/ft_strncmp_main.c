/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:01:27 by creek             #+#    #+#             */
/*   Updated: 2018/12/04 17:12:35 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		main()
{
	char str1[] = "abcbabababfh";
	char str2[] = "abcbabab";
	int n = 4;
	printf("%d\n", ft_strncmp(str1, str2, n));

	char str3[] = "abcbabababfh";
    char str4[] = "abcbabab";
    int m = 4;
    printf("%d\n", strncmp(str3, str4, m));

	return (0);
}

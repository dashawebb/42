/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:05:24 by creek             #+#    #+#             */
/*   Updated: 2018/12/01 20:16:55 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int		main()
{
	char c = 'b';
	char *str1 = "Ulalalabla";
	char *str2 = "Ulalalabla";
	printf("%s\n", strchr(str1, c));
	printf("%s\n", ft_strchr(str2, c));

	char d = 'd';
    char *str3 = "Ulalalabla";
    char *str4 = "Ulalalabla";
    printf("%s\n", strchr(str3, d));
    printf("%s\n", ft_strchr(str4, d));
	return (0);
}

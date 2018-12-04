/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:05:24 by creek             #+#    #+#             */
/*   Updated: 2018/12/01 20:23:36 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int		main()
{
	char c = 'b';
	char *str1 = "Ulablalabla";
	char *str2 = "Ulablalabla";
	printf("%s\n", strrchr(str1, c));
	printf("%s\n", ft_strrchr(str2, c));

	char d = 'd';
    char *str3 = "Ulablalabla";
    char *str4 = "Ulablalabla";
    printf("%s\n", strrchr(str3, d));
    printf("%s\n", ft_strrchr(str4, d));
	return (0);
}

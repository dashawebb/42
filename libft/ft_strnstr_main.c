/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:23:23 by creek             #+#    #+#             */
/*   Updated: 2018/12/04 16:47:30 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		main()
{
	char *haystack1 = "abcdehkoiuhguihgbc";
	char *needle1 = "hk";
	printf("%s\n", strnstr(haystack1, needle1, 5));

	char *haystack3 = "abcdehkoiuhguihgbc";
    char *needle3 = "c";
    printf("%s\n", strnstr(haystack3, needle3, 2));
	char *haystack2 = "abcdehkoiuhguihgbc";
    char *needle2 = "c";
    printf("%s\n", ft_strnstr(haystack2, needle2, 2));
}

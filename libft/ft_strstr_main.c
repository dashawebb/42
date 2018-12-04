/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:23:23 by creek             #+#    #+#             */
/*   Updated: 2018/12/04 16:02:00 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle);

int		main()
{
	char *haystack1 = "abcdehkoiuhguihgbc";
	char *needle1 = "bc";
	printf("%s\n", strstr(haystack1, needle1));

	char *haystack2 = "abcdehkoiuhguihgbc";
    char *needle2 = "bc";
    printf("%s\n", ft_strstr(haystack2, needle2));
}

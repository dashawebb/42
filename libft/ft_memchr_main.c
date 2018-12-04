/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:58:38 by creek             #+#    #+#             */
/*   Updated: 2018/11/26 19:05:36 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

int main(void)
{
    char str[] = "ABCDEFG";
    char *ps = memchr(str,'B',strlen(str));
    if (ps != NULL)
		printf ("search character found:  %s\n", ps);
    else
		printf ("search character not found\n");
	char str1[] = "ABCDEFG";
    char *ps1 = ft_memchr(str1,'B',strlen(str1));
    if (ps1 != NULL)
		printf ("search character found:  %s\n", ps1);
    else
        printf ("search character not found\n");
    return 0;
}

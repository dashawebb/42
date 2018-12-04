/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:42:05 by creek             #+#    #+#             */
/*   Updated: 2018/11/25 22:48:37 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void    ft_bzero(void *s, size_t n);

int main()
{
	char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore bzero(): %s\n", str);

    // Fill 8 characters starting from str[13] with '.'
    bzero(str + 13, 19);

    printf("After bzero():  %s", str);

    char str1[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore ft_bzero(): %s\n", str1);

    // Fill 8 characters starting from str[13] with '.'
    ft_bzero(str1 + 13, 19);

    printf("After ft_bzero():  %s", str1);
    return 0;
}

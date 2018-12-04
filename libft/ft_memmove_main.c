/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:16:00 by creek             #+#    #+#             */
/*   Updated: 2018/11/28 15:59:22 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len);

int main () 
{ 
	char str1[] = "Geeks";  // Array of size 100 
	char str2[]  = "Quiz";  // Array of size 5 

/*	puts("str1 before memmove "); 
	puts(str1); */
  
	/* Copies contents of str2 to sr1 */
	char *s = memmove(NULL, str2, 5); 
	printf ("memmove, %s", s);
	/*puts("\nstr1 after memmove "); 
	  puts(str1); */

    char str3[] = "Geeks";  // Array of size 100
    char str4[]  = "Quiz";  // Array of size 5
/*
    puts("str1 before memmove ");
    puts(str3);*/

    /* Copies contents of str2 to sr1 */
	/*  ft_memmove(NULL, NULL, 5);
	printf("ft_memmove");*/
	/* puts("\nstr1 after memmove ");
	   puts(str3);*/
  
	return 0; 
} 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:18:49 by creek             #+#    #+#             */
/*   Updated: 2018/11/25 22:56:52 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <string.h> 

void	*ft_memset(void *b, int c, size_t len);

/*void	printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; i++) 
		printf("%d ", arr[i]); 
} 
  
int main() 
{ 
    int n = 10; 
    int arr[n]; 
  
    // Fill whole array with 0. 
    ft_memset(arr, 0, n); 
    printf("Array after memset()\n"); 
    printArray(arr, n); 
  
    return 0; 
} */

int main() 
{
	char str[51] = "C is the best programming language somebody kill me";
    printf("\nBefore memset(): %s\n", str);

    // Fill 8 characters starting from str[13] with '.'
    memset(str + 13, '.', 8*sizeof(char));

    printf("After memset():  %s", str);
 
    char str1[51] = "C is the best programming language somebody kill me"; 
    printf("\nBefore ft_memset(): %s\n", str1); 
  
    // Fill 8 characters starting from str[13] with '.' 
    ft_memset(str1 + 13, '.', 8*sizeof(char)); 
  
    printf("After ft_memset():  %s", str1); 
    return 0; 
} 

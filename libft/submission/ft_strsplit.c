/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:49:14 by creek             #+#    #+#             */
/*   Updated: 2018/12/15 15:09:52 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
//
// char **ft_strsplit(char const *s, char c)
//{
// 		char *str;
//
// 		while (str == c)
// 			str++;
// 		if (!(str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
// 			return (NULL);
//
// 		int count;
// 		char *p;
//
//     p = s;
// 		count = 0;
// 		/* counting the amount of words */
//     while (*p != '\0')
//     {
//         if (*p == c)
//             count++;
//         p++;
//     }
//
//
//}

// !!когда буду фришить, нужно удалить все двумерные массивы
// !!>= 0;


// {
// 	int count = 1;
// 	int token_len = 1;
// 	 int i = 0;
// 	 char *p;
// 	 char *t;
// 	 char **arr = NULL;
//
// 	 p = s;
// 	 while (*p != '\0')
// 	 {
// 			 if (*p == c)
// 					 count++;
// 			 p++;
// 	 }
//
// 	 *arr = (char**) malloc(sizeof(char*) * count);
// 	 if (*arr == NULL)
// 			 exit(1);
//
// 	 p = str;
// 	 while (*p != '\0')
// 	 {
// 			 if (*p == c)
// 			 {
// 					 (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
// 					 if ((*arr)[i] == NULL)
// 							 exit(1);
//
// 					 token_len = 0;
// 					 i++;
// 			 }
// 			 p++;
// 			 token_len++;
// 	 }
// 	 (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
// 	 if ((*arr)[i] == NULL)
// 			 exit(1);
//
// 	 i = 0;
// 	 p = s;
// 	 t = ((*arr)[i]);
// 	 while (*p != '\0')
// 	 {
// 			 if (*p != c && *p != '\0')
// 			 {
// 					 *t = *p;
// 					 t++;
// 			 }
// 			 else
// 			 {
// 					 *t = '\0';
// 					 i++;
// 					 t = ((*arr)[i]);
// 			 }
// 			 p++;
// 	 }
// 	 return (arr);
// }

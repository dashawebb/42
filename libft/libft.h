/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:21:16 by creek             #+#    #+#             */
/*   Updated: 2018/12/12 22:31:26 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

void	ft_bzero(void *s, size_t n);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

char	*ft_strcat(char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *src);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *str);

char	*ft_strncat(char *s1, const char *s2, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int     ft_atoi(const char *str);

char	*ft_strncpy(char *dst, const char *src, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *s, int c);

char	*ft_strstr(const char *haystack, const char *needle);

int		ft_tolower(int c);

int		ft_toupper(int c);

void  *ft_memalloc(size_t size);

void  ft_memdel(void **ap);

void  ft_strdel(char **as);

char *ft_strnew(size_t size);

void  ft_strclr(char *s);

void  ft_striter(char *s, void (*f)(char *));

void  ft_striteri(char *s, void (*f)(unsigned int, char *));

char  *ft_strmap(char const *s, char (*f)(char));

char	*ft_itoa(int n);

void	ft_putchar(char c);

void	ft_putstr(char const *s);

void	ft_putnbr(int n);

#endif

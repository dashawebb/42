/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <creek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:03:41 by creek             #+#    #+#             */
/*   Updated: 2018/12/11 15:54:18 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*new_str;
	int		i;

	i = 0;
	len = ft_strlen((char*)src);
	if (!src)
		return (NULL);
	if (!(new_str = (char*)malloc((len + 1) * sizeof(*new_str))))
		return (NULL);
	while ((new_str[i] = src[i]) != '\0')
		i++;
	return (new_str);
}

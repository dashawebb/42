/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchrist <elchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:05:48 by elchrist          #+#    #+#             */
/*   Updated: 2018/12/07 22:57:54 by elchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	if (size < size + 1)
	{
		return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
	}
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:43:51 by creek             #+#    #+#             */
/*   Updated: 2018/12/13 13:44:32 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memory;

	if (!(memory = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}

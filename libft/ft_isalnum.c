/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creek <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:36:18 by creek             #+#    #+#             */
/*   Updated: 2018/12/04 20:39:05 by creek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isalnum(int c)
{
	unsigned char letter;

	letter = (unsigned char)c;
	if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || (letter >= 49 && letter <=57))
		return (1);
	else
		return (0);
}

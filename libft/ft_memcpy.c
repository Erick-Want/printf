/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:59:23 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/14 14:33:39 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	i = 0;
	if (!src && !dest)
		return (NULL);
	dest1 = dest;
	src1 = src;
	while (n > i)
	{
		dest1[i] = src1[i];
		i++;
	}
	return ((void *)dest1);
}

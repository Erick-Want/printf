/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:00:14 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/05 15:00:15 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	len_dest;

	i = 0;
	x = 0;
	len_dest = ft_strlen(dest);
	if (size < len_dest)
		return (ft_strlen(src) + size);
	while (dest[i] != '\0')
		i++;
	while (size > i + 1 && src[x] != '\0')
	{
		dest[i] = src[x];
		x++;
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (len_dest + ft_strlen(src));
}

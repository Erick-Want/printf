/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:26:57 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/11 15:45:10 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	size_t	match;

	i = 0;
	len_little = 0;
	match = 0;
	if (little[i] == '\0')
		return ((char *)&big[i]);
	while (little[len_little] != '\0')
		len_little++;
	while (big[i] != '\0' && len >= len_little)
	{
		while (big[i + match] == little[match])
		{
			if (match + 1 == len_little)
				return ((char *)&big[i]);
			match++;
		}
		match = 0;
		len--;
		i++;
	}
	return (NULL);
}

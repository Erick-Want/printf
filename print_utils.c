/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 16:31:45 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/17 18:41:53 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_len_int(size_t n)
{
	size_t	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa_sizet(size_t n)
{
	char	*s;
	size_t	i;

	i = ft_len_int(n);
	if (n == 0)
	{
		s = ft_calloc(sizeof(char), 2);
		if (!s)
			return (NULL);
		s[0] = '0';
		return (s);
	}
	s = malloc(sizeof(char) * i + 1);
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	while (n != 0)
	{
		s[--i] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

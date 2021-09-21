/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:35:59 by ermatheu          #+#    #+#             */
/*   Updated: 2021/08/18 11:38:43 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_len_int(int n)
{
	unsigned int	size;

	size = 0;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*copy(unsigned int nb, size_t i, char *s)
{
	s[i] = '\0';
	while (nb != 0)
	{
		s[--i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (s);
}

char	*is_zero(int n)
{
	char	*s;

	n = 2;
	s = malloc(sizeof(char) * n);
	if (!s)
		return (NULL);
	s[0] = 48;
	s[1] = 0;
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	int				i;

	i = ft_len_int(n);
	nb = n;
	if (n == 0)
		return (is_zero(n));
	if (n < 0)
	{
		nb = n * (-1);
		s = malloc(sizeof(char) * i + 2);
		if (!s)
			return (NULL);
		i++;
		s[0] = '-';
	}
	else
	{
		s = malloc(sizeof(char) * i + 1);
		if (s == NULL)
			return (NULL);
	}
	return (copy(nb, i, s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:39:04 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/08 10:39:37 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hex_len(size_t convert)
{
	int	i;

	i = 0;
	while (convert)
	{
		convert = convert / 16;
		i++;
	}
	return (i);
}

int	print_address(size_t convert)
{
	char	*s;
	char	*hex;
	int		i;

	s = "0123456789abcdef";
	i = hex_len(convert);
	hex = malloc (sizeof(char) * i + 3);
	hex[0] = '0';
	hex[1] = 'X';
	hex[i] = '\0';
	while (i)
	{
		hex[--i + 2] = s[(convert % 16)];
		convert = convert / 16;
	}
	print_string(hex);
	free(hex);
	return (hex_len(convert) + 2);
}


int	print_hex(size_t convert, char c)
{
	char	*s;
	char	*hex;
	int		i;

	s = "0123456789abcdef";
	if (c == 'X')
		s = "0123456789ABCDEF";
	i = hex_len(convert);
	hex = malloc (sizeof(char) * i + 1);
	hex[i] = '\0';
	while (i)
	{
		hex[--i] = s[(convert % 16)];
		convert = convert / 16;
	}
	print_string(hex);
	free(hex);
	return (hex_len(convert));
}

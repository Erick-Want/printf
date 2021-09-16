/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:39:04 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/16 16:07:04 by ermatheu         ###   ########.fr       */
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
	size_t	ret;

	s = "0123456789abcdef";
	ret = convert;
	i = hex_len(convert);
	hex = malloc (sizeof(char) * i + 3);
	if (!hex)
		return (0);
	hex[0] = '0';
	hex[1] = 'x';
	hex[i] = '\0';
	while (i)
	{
		hex[--i + 2] = s[(convert % 16)];
		convert = convert / 16;
	}
	print_string(hex);
	//free(hex);
	return (hex_len(ret) + 2);
}

int	print_hex(t_param *storage, size_t convert)
{
	char	*s;
	char	*hex;
	int		i;
	size_t	ret;

	s = "0123456789abcdef";
	ret = convert;
	if (storage->types == 'X')
		s = "0123456789ABCDEF";
	i = hex_len(convert);
	// // if (i == 0)
	// // {
	// // 	hex = ft_calloc(sizeof(char), 2);
	// // 	hex[0] = '0';
	// // 	convert = 1;
	// // }
	// else
		hex = ft_calloc(sizeof(char), i + 1);
	while (i)
	{
		hex[--i] = s[(convert % 16)];
		convert = convert / 16;
	}
	i = general_flags_hex(storage, hex);
	free(hex);
	return (i + hex_len(ret) + convert);
}

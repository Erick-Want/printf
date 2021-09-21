/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:39:04 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/21 14:55:25 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	print_address(size_t convert, t_param *storage)
{
	char	*s;
	char	*hex;
	int		i;
	size_t	ret;

	s = "0123456789abcdef";
	ret = convert;
	i = hex_len(convert);
	if (convert == 0)
	{
		write (1, "0x0", 3);
		return (3);
	}
	hex = malloc (sizeof(char) * i + 3);
	if (!hex)
		return (0);
	i = copy_string_hex(hex, convert, s, storage);
	print_string(hex, storage);
	free(hex);
	return (hex_len(ret) + 2);
}

int	copy_string_hex(char *hex, size_t convert, char *s, t_param *storage)
{
	int	i;

	i = hex_len(convert);
	if (storage->types == 'p')
	{
		hex[0] = '0';
		hex[1] = 'x';
		hex[i + 2] = '\0';
		while (i)
		{
			hex[--i + 2] = s[(convert % 16)];
			convert = convert / 16;
		}
	}
	else
	{
		while (i)
		{
			hex[--i] = s[(convert % 16)];
			convert = convert / 16;
		}
	}
	return (i);
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
	if (convert == 0 && !(storage->precision)
		&& !(ft_strchr(storage->flags, '#')))
	{
		hex = ft_calloc(sizeof(char), 2);
		hex[0] = 48;
		i = general_flags_hex(storage, hex);
		free(hex);
		return (i + 1);
	}
	i = hex_len(convert);
	hex = ft_calloc(sizeof(char), i + 1);
	i = copy_string_hex(hex, convert, s, storage)
		+ general_flags_hex(storage, hex);
	free(hex);
	return (i + hex_len(ret));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:26:01 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/22 14:50:55 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_precision_size(t_param *storage, char *s)
{
	int	count;
	int	len;
	int	size;

	if (storage->nb_aux < 0)
		write (1, "-", 1);
	if (storage->size == 0)
		return (0);
	count = 0;
	size = storage->size;
	len = ft_strlen_mod(s);
	while ((size - len > 0))
	{
		write (1, "0", 1);
		count++;
		size--;
	}
	return (count);
}

int	general_flags_p(t_param *storage, size_t convert)
{
	int		count;
	char	*str;

	count = 0;
	storage->nb_hex = convert;
	if (ft_strchr(storage->flags, ' '))
		count = count + flag_space(storage);
	str = str_flags_p(storage, convert);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, str);
		count = count + flag_precision_size(storage, str);
		count = count + print_address(convert, storage);
	}
	else if (storage->len_min < 0)
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_address(convert, storage);
		count = count + flag_width(storage, str);
	}
	else
		count = count + print_address(convert, storage);
	free(str);
	return (count);
}

int	general_flags_u(t_param *storage, unsigned int nb)
{
	int		count;
	char	*str;

	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	str = ft_itoa_sizet(nb);
	if (storage->len_min > 0)
	{
		count = flag_width(storage, str);
		count = count + flag_precision_size(storage, str);
		count = count + print_unsigned(nb, storage);
	}
	else if (storage->len_min < 0)
	{
		count = flag_precision_size(storage, str);
		count = count + print_unsigned(nb, storage);
		count = count + flag_width(storage, str);
	}
	else
	{
		count = flag_precision_size(storage, str);
		count = count + print_unsigned(nb, storage);
	}
	free(str);
	return (count);
}

int	general_flags_hex(t_param *storage, char *hex)
{
	int		count;

	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	if (storage->len_min > 0)
	{
		count = flag_width(storage, hex);
		count = count + flag_precision_size(storage, hex);
		count = count + flag_hash(storage, hex);
		print_string(hex, storage);
	}
	else if (storage->len_min < 0)
	{
		count = flag_hash(storage, hex);
		count = count + flag_precision_size(storage, hex);
		print_string(hex, storage);
		count = count + flag_width(storage, hex);
	}
	else
	{
		count = flag_precision_size(storage, hex);
		count = count + flag_hash(storage, hex);
		print_string(hex, storage);
	}
	return (count);
}

int	general_flags_c(t_param *storage, char c)
{
	int		count;
	char	*str;

	count = 0;
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	str = "c";
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, str);
		count = count + print_char(c);
	}
	else if (storage->len_min < 0)
	{
		count = count + print_char(c);
		count = count + flag_width(storage, str);
	}
	else
		count = count + print_char(c);
	return (count);
}

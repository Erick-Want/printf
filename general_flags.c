/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:26:01 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/16 17:26:19 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	flag_precision_size(t_param *storage, char *s)
{
	int	count;
	int	len;
	int	size;

	// if (s[0] == '-')
	// 	write (1, "-", 1);
	if (storage->size == 0)
		return (0);
	count = 0;
	size = storage->size;
	// if (s[0] == '-')
	// {
	// 	write (1, "-", 1);
	// 	count++;
	// 	size = size + 1;
	// }
	len = ft_strlen(s);
	while ((size - len > 0))
	{
		write (1, "0", 1);
		count++;
		size--;
	}
	return (count);
}

int	flag_width(t_param *storage, char *s)
{
	int	count;
	int	len;
	int	width;

	count = 0;
	len = ft_strlen(s);
	width = storage->len_min;
	if (storage->len_min < 0)
		storage->len_min = storage->len_min * (-1);
	while ((storage->len_min - len > 0) && storage->len_min > storage->size)
	{
		if (ft_strchr(storage->flags, '0') && width > 0
		&& !(storage->types == 'c') && !(storage->precision))
		{
			write (1, "0", 1);
			count++;
		}
		else
		{
			write (1, " ", 1);
			count++;
		}
		storage->len_min--;
	}
	return (count);
}

int	general_flags_d(t_param *storage, int nb)
{
	int		count;
	char	*str;

	count = 0;
	if (ft_strchr(storage->flags, '+') && nb >= 0)
		count = count + flag_plus(storage);
	if (ft_strchr(storage->flags, ' ') && (!ft_strchr(storage->flags, '+'))
	&& nb >= 0)
		count = count + flag_space(storage);
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	if (nb == 0 && storage->precision)
		str = ft_calloc(sizeof(char), 1);
	else
		str = ft_itoa(nb);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, str);
		count = count + flag_precision_size(storage, str);
		count = count + print_string(str);
	}
	else if (storage->len_min < 0)
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_string(str);
		count = count + flag_width(storage, str);
	}
	else
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_string(str);
	}
	free(str);
	return (count);
}

char	*new_string_cut_precision(t_param *storage, char *s)
{
	char	*new;

	if (storage->precision)
	{
		new = ft_substr(s, 0, storage->size);
		return (new);
	}
	else
		return(s);
}

int	general_flags_s(t_param *storage, char *s)
{
	int		count;
	char	*s1;

	count = 0;
	if (!s)
	{
		s = new_string_cut_precision(storage, "(null)");
		print_string(s);
		count = ft_strlen(s);
		free(s);
		return (count);
	}
	s1 = s;
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	if (storage->len_min > 0)
	{
		s = new_string_cut_precision(storage, s);
		count = count + flag_width(storage, s);//DETALHE IMPORTANTE LEN < SIZE
		count = count + print_string(s);
	}
	else if (storage->len_min < 0)
	{
		s = new_string_cut_precision(storage, s);
		count = count + print_string(s);
		count = count + flag_width(storage, s);
	}
	else
	{
		s = new_string_cut_precision(storage, s);
		count = count + print_string(s);
	}
	if (storage->precision)
		free(s);
	return (count);
}

int	general_flags_p(t_param *storage, size_t convert)
{
	int		count;
	char	*str;

	count = 0;
	if (ft_strchr(storage->flags, ' '))
		count = count + flag_space(storage);
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	str = ft_itoa_sizet(convert);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, str);
		count = count + flag_precision_size(storage, str);
		count = count + print_address(convert);
	}
	else if (storage->len_min < 0)
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_address(convert);
		count = count + flag_width(storage, str);
	}
	else
		count = count + print_address(convert);
	free(str);
	return (count);
}

int	general_flags_u(t_param *storage, unsigned int nb)
{
	int		count;
	char	*str;

	count = 0;
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	str = ft_itoa_sizet(nb);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, str);
		count = count + flag_precision_size(storage, str);
		count = count + print_unsigned(nb, storage);
	}
	else if (storage->len_min < 0)
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_unsigned(nb, storage);
		count = count + flag_width(storage, str);
	}
	else
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_unsigned(nb, storage);
	}
	free(str);
	return (count);
}

int	general_flags_hex(t_param *storage, char *hex)
{
	int		count;

	count = 0;
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, hex);
		count = count + flag_precision_size(storage, hex);
		count = count + flag_hash(storage, hex);
		print_string(hex);
	}
	else if (storage->len_min < 0)
	{
		count = count + flag_hash(storage, hex);
		count = count + flag_precision_size(storage, hex);
		print_string(hex);
		count = count + flag_width(storage, hex);
	}
	else
	{
		count = count + flag_precision_size(storage, hex);
		count = count + flag_hash(storage, hex);
		print_string(hex);
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
		//count = count + flag_precision_size(storage, str);
		count = count + print_char(c);
	}
	else if (storage->len_min < 0)
	{
		//count = count + flag_precision_size(storage, str);
		count = count + print_char(c);
		count = count + flag_width(storage, str);
	}
	else
		count = count + print_char(c);
	return (count);
}

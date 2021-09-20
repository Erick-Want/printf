/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:26:01 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/20 16:00:57 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int	print_width(t_param *storage, int width, char *s)
{
	int	count;
	int	len;
	int	aux;

	aux = 0;
	count = 0;
	len = ft_strlen(s);
	while ((storage->len_min - len > 0) && storage->len_min > storage->size)
	{
		if (ft_strchr(storage->flags, '0') && width > 0
			&& !(storage->types == 'c') && !(storage->precision))
			count = count + flag_zero(storage);
		else
		{
			write (1, " ", 1);
			count++;
			aux++;
			if ((s[0] == '-' && (storage->len_min - storage->size + 1 == len))
				&& ((storage->types == 'd') || (storage->types == 'i')))
				len++;
		}
		storage->len_min--;
	}
	return (count);
}

int	flag_width(t_param *storage, char *s)
{
	int	count;
	int	width;

	width = storage->len_min;
	if (storage->len_min < 0)
		storage->len_min = storage->len_min * (-1);
	count = print_width(storage, width, s);
	return (count);
}

int	general_flags_d(t_param *storage, int nb)
{
	int		count;
	char	*str;

	count = 0;
	if (nb < 0)
		storage->nb_aux = nb;
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
		count = count + print_string(str, storage);
	}
	else if (storage->len_min < 0)
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_string(str, storage);
		count = count + flag_width(storage, str);
	}
	else
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_string(str, storage);
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
		if (!new)
			return (NULL);
		return (new);
	}
	else
		return (s);
}

int	print_flags_s_null(t_param *storage, char *s)
{
	int		count;
	char	*s1;

	count = 0;
	if (!s)
	{
		s1 = new_string_cut_precision(storage, "(null)");
		count = count + flag_width(storage, s1);
		count = count + print_string(s1, storage);
		if (storage->precision)
			free(s1);
		return (count);
	}
	return (count);
}

int	general_flags_s(t_param *storage, char *s)
{
	int	count;

	count = 0;
	count = print_flags_s_null(storage, s);
	if (count != 0)
		return (count);
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	s = new_string_cut_precision(storage, s);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, s);
		count = count + print_string(s, storage);
	}
	else if (storage->len_min < 0)
	{
		count = count + print_string(s, storage);
		count = count + flag_width(storage, s);
	}
	else
		count = count + print_string(s, storage);
	if (storage->precision)
		free(s);
	return (count);
}

char	*str_flags_p(t_param *storage, size_t convert)
{
	char	*str;

	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	str = ft_itoa_sizet(convert);
	if (convert == 0 && storage->len_min > 0)
		storage->len_min = storage->len_min - 2;
	else if (convert == 0 && storage->len_min < 0)
		storage->len_min = storage->len_min + 2;
	return (str);
}

int	general_flags_p(t_param *storage, size_t convert)
{
	int		count;
	char	*str;

	count = 0;
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

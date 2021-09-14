/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:26:01 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/14 14:08:02 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	flag_precision_size(t_param *storage, char *s)
{
	int	count;
	int	len;
	int	size;

	if (storage->size == 0)
		return (0);
	count = 0;
	len = ft_strlen(s);
	size = storage->size;
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
		if (ft_strchr(storage->flags, '0') && width > 0)
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
	if (ft_strchr(storage->flags, '+') && nb > 0)
		count = count + flag_plus(storage);
	if (ft_strchr(storage->flags, ' ') && (!ft_strchr(storage->flags, '+'))
	&& nb >= 0)
		count = count + flag_space(storage);
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	str = ft_itoa(nb);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, str);
		count = count + flag_precision_size(storage, str);
		count = count + print_number(nb);
	}
	else if (storage->len_min < 0)
	{
		count = count + flag_precision_size(storage, str);
		count = count + print_number(nb);
		count = count + flag_width(storage, str);
	}
	else
		count = count + print_number(nb);
	free(str);
	return (count);
}

int	general_flags_s(t_param *storage, char *s)
{
	int		count;

	count = 0;
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, s);//DETALHE IMPORTANTE LEN < SIZE
		count = count + print_string(s);
	}
	else if (storage->len_min < 0)
	{
		count = count + print_string(s);
		count = count + flag_width(storage, s);
	}
	else
		count = count + print_string(s);
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
	str = ft_itoa(convert);//DETALHE IMPORTANTE (SIZE_T)
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
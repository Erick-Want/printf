/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:45:24 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/22 14:46:39 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width(t_param *storage, int width, char *s)
{
	int	count;
	int	len;

	count = 0;
	if (storage->types == 'p' && !(s[0] == '0'
			&& ((size_t)hex_len(storage->nb_hex) != ft_strlen(s)
				|| (ft_strchr(storage->flags, '0')))))
		len = hex_len(storage->nb_hex) + 2;
	else
		len = ft_strlen(s);
	while ((storage->len_min - len > 0)
		&& ((storage->len_min > storage->size) || (storage->types == 's')))
	{
		if (ft_strchr(storage->flags, '0') && width > 0
			&& !(storage->types == 'c') && !(storage->precision))
			count = count + flag_zero(storage);
		else
		{
			write (1, " ", 1);
			count++;
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

	if (storage->len_min > 0 && s[0] == '-' && storage->size
		&& !(storage->len_min - storage->size - ft_strlen(s) == 1))
		storage->len_min--;
	width = storage->len_min;
	if (storage->len_min < 0)
		storage->len_min = storage->len_min * (-1);
	count = print_width(storage, width, s);
	return (count);
}

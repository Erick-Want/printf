/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_save.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:38:04 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/22 15:26:39 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	type_specifier(t_param *storage, const char *s, size_t i)
{
	if (ft_strchr(TYPES, s[i]))
	{
		storage->types = s[i];
		i++;
	}
	return (i);
}

size_t	storage_flags(t_param *storage, const char *s, size_t i)
{
	size_t	index;

	index = 0;
	while (ft_strchr(FLAGS, s[i]))
	{
		if (!ft_strchr(storage->flags, s[i]))
		{
			storage->flags[index] = s[i];
			index++;
		}
		i++;
	}
	return (i);
}

size_t	storage_width_precision_size(t_param *storage, const char *s, size_t i)
{
	int	res;

	if (ft_isdigit(s[i]))
	{
		res = s[i] - 48;
		while (ft_isdigit(s[++i]))
			res = (res * 10) + s[i] - 48;
		storage->len_min = res;
	}
	if (s[i] == '.')
	{
		res = 0;
		storage->precision = 1;
		if (ft_isdigit(s[++i]))
			res = s[i++] - 48;
		while (ft_isdigit(s[i]))
			res = (res * 10) + s[i++] - 48;
		storage->size = res;
	}
	return (i);
}

size_t	check_and_save(t_param *storage, const char *s, size_t i)
{
	if (s[i] == '%')
		i++;
	if (ft_strchr(FLAGS, s[i]))
		i = storage_flags(storage, s, i);
	i = storage_width_precision_size(storage, s, i);
	if (ft_strchr(TYPES, s[i]))
		storage->types = s[i++];
	else
		return (0);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_save.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:38:04 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/02 14:29:59 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == '\0' && (char) c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t type_specifier(s_params *storage, const char *s, size_t i)
{
	if (ft_strchr(TYPES, s[i]))
	{
		storage->types = s[i];
		i++;
	}
	return (i);
}

//cspdiuxX%

size_t	storage_flags(s_params *storage, const char *s, size_t i)
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

size_t	storage_width_precision_size(s_params *storage, const char *s, size_t i)
{
	int	res;

	res = s[i] - 48;
	while (ft_isdigit(s[++i]))
		res = (res * 10) + s[i] - 48;
	storage->len_min = res;
	if (s[i] == '.')
	{
		storage->precision = 1;
		if (ft_isdigit(s[++i]))
			res = s[i] - 48;
		while (ft_isdigit(s[++i]))
			res = (res * 10) + s[i] - 48;
		storage->size = res;
	}
	return (i);
}

size_t	check_and_save(s_params *storage, const char *s, size_t i)
{
	if (s[i] == '%')
		i++;
	if (ft_strchr(FLAGS, s[i]))
		i = storage_flags(storage, s, i);
	if (ft_isdigit(s[i]))
		i = storage_width_precision_size(storage, s, i);
	if (ft_strchr(TYPES, s[i]))
		storage->types = s[i++];
	else
		return (0);
	return (i);
}

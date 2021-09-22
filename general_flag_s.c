/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_flags_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:39:41 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/22 14:40:17 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

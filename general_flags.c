/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:26:01 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/10 17:01:01 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	flag_width(t_param *storage, char *s)
{
	int	count;
	int	len;
	int	width;

	count = 0;
	len = ft_strlen(s);
	if (storage->len_min < 0)
		width = storage->len_min * (-1);
	else
		width = storage->len_min;
	while ((width - len > 0))
	{
		if (ft_strchr(storage->flags, '0') && storage->len_min > 0)
		{
			write (1, "0", 1);
			count++;
		}
		else
		{
			write (1, " ", 1);
			count++;
		}
		width--;
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
	if (ft_strchr(storage->flags, ' ') && (!ft_strchr(storage->flags, '+')))
		count = count + flag_space(storage);
	if (ft_strchr(storage->flags, '-'))
		flags_minus(storage);
	str = ft_itoa(nb);
	if (storage->len_min > 0)
	{
		count = count + flag_width(storage, str);
		count = count + print_number(nb);
	}
	else if (storage->len_min < 0)
	{
		count = count + print_number(nb);
		count = count + flag_width(storage, str);
	}
	else
		count = count + print_number(nb);
	free(str);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:18:57 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/10 16:54:25 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flags_minus(t_param *storage)
{
	if (ft_strchr(storage->flags, '-') && (storage->len_min > 0))
		storage->len_min = storage->len_min * (-1);
}

int	flag_space(t_param *storage)
{
	int	count;

	count = 0;
	if (ft_strchr(storage->flags, ' '))
	{
		write (1, " ", 1);
		count++;
	}
	return (count);
}

int	flag_zero(t_param *storage)
{
	int	count;

	count = 0;
	if (ft_strchr(storage->flags, '0'))
	{
		write (1, "0", 1);
		count++;
	}
	return (count);
}

int	flag_plus(t_param *storage)
{
	int	count;

	count = 0;
	if (ft_strchr(storage->flags, '+'))
	{
		write (1, "+", 1);
		count++;
	}
	return (count);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:18:57 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/21 14:13:54 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (storage->nb_aux < 0 && ((storage->types == 'd')
		|| (storage->types == 'i')))
	{
		write (1, "-", 1);
		storage->nb_aux = 0;
		storage->sign = 1;
		//count++;
	}
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

int	flag_hash(t_param *storage, char *hex)
{
	int	count;

	count = 0;
	if (ft_strchr(storage->flags, '#'))
	{
		if (storage->types == 'o' || hex[0] == 0)
		{
			write (1, "0", 1);
			count = 1;
		}
		else if (storage->types == 'x')
		{
			write (1, "0x", 2);
			count = 2;
		}
		else if (storage->types == 'X')
		{
			write (1, "0X", 2);
			count = 2;
		}
	}
	return (count);
}

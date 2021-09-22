/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_flag_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:50:26 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/22 15:07:02 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width_d(t_param *storage, char *str)
{
	int	count;

	count = 0;
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
	count = count + print_width_d(storage, str);
	free(str);
	return (count);
}

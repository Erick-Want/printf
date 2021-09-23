/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:23:51 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/23 13:28:55 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise_struct(t_param *storage)
{
	ft_bzero(storage->flags, 7);
	storage->len_min = 0;
	storage->precision = 0;
	storage->size = 0;
	storage->types = ' ';
	storage->nb_aux = 0;
	storage->sign = 0;
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;
	size_t	i;
	t_param	storage;

	i = 0;
	count = 0;
	va_start(arg, s);
	while (s[i])
	{
		initialise_struct(&storage);
		if (s[i] == '%' && check_and_save(&storage, s, i))
		{
			i = check_and_save(&storage, s, i);
			count = count + print_storage(&storage, arg);
		}
		else
		{
			write (1, &s[i], 1);
			i++;
			count++;
		}
	}
	va_end(arg);
	return (count);
}

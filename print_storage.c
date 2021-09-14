/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_storage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:34:34 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/14 14:07:06 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_string(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	print_number(int nb)
{
	unsigned int	nbr;
	int				count;

	count = 0;
	if (nb < 0)
	{
		write (1, "-", 1);
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	while (nb != 0)
	{
		count++;
		nb = nb / 10;
	}
	if (nbr >= 10)
		print_number(nbr / 10);
	print_char((char)(nbr % 10 + 48));
	return (count);
}

int	print_unsigned(size_t nb)
{
	int		count;
	size_t	nbr;

	count = 0;
	nbr = nb;
	while (nbr != 0)
	{
		count++;
		nbr = nbr / 10;
	}
	if (nb >= 10)
		print_number(nb / 10);
	print_char((char)(nb % 10 + 48));
	return (count);
}

int	print_storage(t_param *storage, va_list arg)
{
	int	count;

	count = 0;
	if (storage->types == 'c')
		count = count + print_char(va_arg(arg, int));
	else if (storage->types == 's')
		count = count + general_flags_s(storage, va_arg(arg, char *));
	else if (storage->types == 'd' || storage->types == 'i')
		count = count + general_flags_d(storage, va_arg(arg, int));
	else if (storage->types == 'p')
		count = count + general_flags_p(storage, va_arg(arg, size_t));
	else if (storage->types == 'u')
		count = count + print_unsigned(va_arg(arg, unsigned int));
	else if (storage->types == 'x' || storage->types == 'X')
		count = count + print_hex(va_arg(arg, size_t), storage->types);
	else if (storage->types == '%')
		count = count + print_char('%');
	return (count);
}

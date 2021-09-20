/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_storage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:34:34 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/20 15:04:11 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_string(char *s, t_param *storage)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	if (storage->nb_aux < 0 || storage->sign)
	{
		count++;
		i++;
	}
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
	if (nb == 0)
		count++;
	if (nb < 0)
	{
		write (1, "-", 1);
		count++;
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

int	print_unsigned(size_t nb, t_param *storage)
{
	int		count;
	size_t	nbr;

	count = 0;
	if (nb == 0 && !(storage->size) && storage->precision)
	{
		if (!(storage->size) && !(storage->len_min))
			return (0);
		write (1, " ", 1);
		return (1);
	}
	else if (nb == 0)
		count++;
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
		count = count + general_flags_c(storage, va_arg(arg, int));
	else if (storage->types == 's')
		count = count + general_flags_s(storage, va_arg(arg, char *));
	else if (storage->types == 'd' || storage->types == 'i')
		count = count + general_flags_d(storage, va_arg(arg, int));
	else if (storage->types == 'p')
		count = count + general_flags_p(storage, va_arg(arg, size_t));
	else if (storage->types == 'u')
		count = count + general_flags_u(storage, va_arg(arg, unsigned int));
	else if (storage->types == 'x' || storage->types == 'X')
		count = count + print_hex(storage, va_arg(arg, size_t));
	else if (storage->types == 'o')
		count = count + print_hex(storage, va_arg(arg, size_t));
	else if (storage->types == '%')
		count = count + print_char('%');
	return (count);
}

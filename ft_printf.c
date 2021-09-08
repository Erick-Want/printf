/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:23:51 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/08 11:14:29 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list		arg;
	int			count;
	size_t		i;
	t_param		storage;

	i = 0;
	count = 0;
	va_start(arg, s);
	ft_bzero(storage.flags, 7);
	while (s[i])
	{
		if (s[i] == '%' && check_and_save(&storage, s, i))
		{
			i = check_and_save(&storage, s, i);
			count = count + print_storage(&storage, arg);
		}
			//função pra identificar o tipo e mandar printar de acordo com as flags ativas
		else
		{
			write (1, &s[i], 1);
			i++;
			count++;
		}
	}
	printf("%s\n%c\n%d\n%d\n%d\n", storage.flags, storage.types, storage.len_min, storage.precision, storage.size);
	va_end(arg);
	return (count);
}

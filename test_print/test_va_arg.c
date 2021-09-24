/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_va_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:31:13 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/23 13:09:40 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(char const *s, ...)
{
	va_list	arg;
	char	*s1;
	int		i;
	char	c;

	i = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			c = va_arg(arg, int);
			printf("%c\n", c);
			i++;
		}
		else
		{
			write (1, &s[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (0);
}
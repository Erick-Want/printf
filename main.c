/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:52:35 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/06 17:07:00 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	unsigned int	num = 1254;
	char	*pointer = "Erick";
	// char	e = 'l';

	ft_printf("Hexadecimal |%X|\n|%u|\n|%p|\n", num, num, pointer);//"letra%+ +-0#+-89.58s\n"
	printf("|%p|\n", pointer);
	return (0);
}
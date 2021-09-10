/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:52:35 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/10 17:25:59 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	unsigned int	num = 1254;
	char			*pointer = "Erick";
	char			e = 'l';

	//ft_printf("Hexadecimal |%X|\n|%u|\n|%p|\n", num, num, pointer);
	//"letra%+ +-0#+-89.58s\n"
	ft_printf("|%-10d|\n", num);
	//cspdiuxX
	return (0);
}
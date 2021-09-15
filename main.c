/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:52:35 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/15 15:28:54 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	unsigned int	num = 1254;
	int				ret = 0;
	char			*pointer = "Erick";
	char			e = 'l';

	//ft_printf("Hexadecimal |%X|\n|%u|\n|%p|\n", num, num, pointer);
	//"letra%+ +-0#+-89.58s\n"
	ret = ft_printf("%-10.15i", (int)-2147483648);
	printf("|%d|\n", ret);
	ret = printf("%-10.15i", (int)-2147483648);
	printf("|%d|\n", ret);
	//ret = printf("|%- 10d|\n", num);
	//printf("|%-.6d|\n", num);
	//cspdiuxX
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:52:35 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/21 15:51:37 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	unsigned int	num = 1254;
	int				ret = 0;
	char			*null_str = NULL;
	char			*pointer = "SE";
	char			e = 'l';

	//ft_printf("Hexadecimal |%X|\n|%u|\n|%p|\n", num, num, pointer);
	//"letra%+ +-0#+-89.58s\n"
	//ret = ft_printf("|%012i, %20i, %2i, %000042i|\n", (int)-2147483648, 3, 30, -1);
	//ft_printf("%-x", 0);
	//ft_printf("%-1x", 0);
	ret = ft_printf("%10.5d", -42);
	printf(" R: |%d|\n", ret);
	ret = printf("%10.5d", -42);
	printf(" R: |%d|\n", ret);
	//ret = printf("|%- 10d|\n", num);
	//printf("|%-.6d|\n", num);0x7ffe8b418048
	//cspdiuxX
	return (0);
}

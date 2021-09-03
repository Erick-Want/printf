/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:52:35 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/03 12:48:27 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main()
{
	unsigned int	num = -1;
	char	*pointer = "Erick";
	char	e = 'l';

	ft_printf("Nome |%p|\n|%u|\n|%c|\n|%%|\n", pointer, num, e);//"letra%+ +-0#+-89.58s\n"
	//printf("|%+5+.3d|\n", num);
	return (0);
}
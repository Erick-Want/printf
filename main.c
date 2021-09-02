/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:52:35 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/02 14:52:42 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main()
{
	int	num = 42;
	char	*pointer = "erick";

	ft_printf("letra%+ +-0#+-89.58s\n", pointer);
	//printf("|%+5.3d|\n", num);
	return (0);
}
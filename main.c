/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 14:52:35 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/21 16:39:35 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	unsigned int	num = 1254;
	int				ret = 0;
	char			*pointer = "ERICK";

	ret = ft_printf(" %-1p %-2p ", 0, 0);
	printf(" R: |%d|\n", ret);
	ret = printf(" %-1p %-2p ", 0, 0);
	printf(" R: |%d|\n", ret);
	return (0);
}

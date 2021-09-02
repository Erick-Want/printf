/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:23:51 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/02 19:07:38 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list		arg;
	int			count;
	size_t		i;
	s_params	storage;

	i = 0;
	count = 0;
	va_start(arg, s);
	ft_bzero(storage.flags, 7);
	while (s[i])
	{
		if (s[i] == '%' && check_and_save(&storage, s, i))
			i = check_and_save(&storage, s, i);
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

// pseudocodigo printf
// criar uma struct para armazenar os parametros (flags, tam min, precisão e tam em bytes)
// criar uma struct para armazenas os tipos a serem printados de acordo com o caracter encontrado
// percorrer a string "s" e ir printando caracteres enquanto não achar o %
// apos encontrar o % mandar para a função que busque os proximos parametros (flags, tam min, precisão e tam em bytes)
// nessa função de buscar os parametros vou procurar pelas flags / tamanho min / precisão / tamanho em bytes
// ativar os parametros encontrados em uma struct
// depois disso encontrar o caracter que identifica o tipo
// mandar buscar qual é o caracter e ativar na struct o tipo encontrado
// printar de acordo com o tipo encontrado considerando os parametros armazenados
// limpar a struct para uma possivel proxima %
// apos isso fazer o processo dinovo até o final da string
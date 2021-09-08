/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:15:29 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/08 10:35:59 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#define TYPES "cspdiuxX%"
#define FLAGS "+- 0#"
#include "./libft/libft.h"

typedef struct	params
{
	char	types;
	char	flags[7];
	int		precision;
	int		len_min;
	int		size;

}	s_params;

int		ft_printf(const char *, ...);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t type_specifier(s_params *storage, const char *s, size_t i);
size_t	storage_flags(s_params *storage, const char *s, size_t i);
size_t	check_and_save(s_params *storage, const char *s, size_t i);
size_t	storage_width_precision_size(s_params *storage, const char *s, size_t i);
int	print_storage(s_params *storage,va_list arg);
int	print_char(char c);
int	print_string(char *s);
int	print_number(int nb);
int	print_unsigned(size_t nb);
int	hex_len(size_t convert);
int	print_address(size_t convert);
int	print_hex(size_t convert, char c);



#endif
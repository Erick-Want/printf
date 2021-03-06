/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:15:29 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/22 15:39:54 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# define TYPES "cspdiuxX%o"
# define FLAGS "+- 0#"
# include "./libft/libft.h"

typedef struct params
{
	char	types;
	char	flags[7];
	int		precision;
	int		len_min;
	int		size;
	int		nb_aux;
	int		sign;
	size_t	nb_hex;

}	t_param;

// initialization
int		ft_printf(const char *s, ...);
void	initialise_struct(t_param *storage);

// Storage Flags and Parameters
size_t	type_specifier(t_param *storage, const char *s, size_t i);
size_t	storage_flags(t_param *storage, const char *s, size_t i);
size_t	check_and_save(t_param *storage, const char *s, size_t i);
size_t	storage_width_precision_size(t_param *storage, const char *s, size_t i);

// Manager Flags
int		general_flags_d(t_param *storage, int nb);
int		general_flags_s(t_param *storage, char *s);
int		general_flags_p(t_param *storage, size_t convert);
int		general_flags_u(t_param *storage, unsigned int nb);
int		general_flags_hex(t_param *storage, char *hex);
int		general_flags_c(t_param *storage, char c);

// Aplication Flags
int		flag_plus(t_param *storage);
void	flags_minus(t_param *storage);
int		flag_space(t_param *storage);
int		flag_zero(t_param *storage);
int		flag_hash(t_param *storage, char *hex);
int		flag_width(t_param *storage, char *s);
int		flag_precision_size(t_param *storage, char *s);

// Print Flags and Parameters
int		print_storage(t_param *storage, va_list arg);
int		print_char(char c);
int		print_string(char *s, t_param *storage);
int		print_number(int nb);
int		print_unsigned(size_t nb, t_param *storage);
int		print_address(size_t convert, t_param *storage);
int		print_hex(t_param *storage, size_t convert);
int		print_width(t_param *storage, int width, char *s);
int		print_width_d(t_param *storage, char *str);

// Utils
int		hex_len(size_t convert);
size_t	ft_strlen_mod(const char *s);
int		len_string(t_param *storage, char *s);
char	*ft_itoa_sizet(size_t n);
char	*str_flags_p(t_param *storage, size_t convert);
char	*new_string_cut_precision(t_param *storage, char *s);
int		copy_string_hex(char *hex, size_t convert, char *s, t_param *storage);

#endif
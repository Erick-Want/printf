/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ermatheu <ermatheu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:15:29 by ermatheu          #+#    #+#             */
/*   Updated: 2021/09/15 15:48:02 by ermatheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
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

}	t_param;

int		ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	type_specifier(t_param *storage, const char *s, size_t i);
size_t	storage_flags(t_param *storage, const char *s, size_t i);
size_t	check_and_save(t_param *storage, const char *s, size_t i);
size_t	storage_width_precision_size(t_param *storage, const char *s, size_t i);
int		print_storage(t_param *storage, va_list arg);
int		print_char(char c);
int		print_string(char *s);
int		print_number(int nb);
int	print_unsigned(size_t nb, t_param *storage);
int		hex_len(size_t convert);
int		print_address(size_t convert);
int	print_hex(t_param *storage, size_t convert);
int	flag_plus(t_param *storage);
void	flags_minus(t_param *storage);
int	flag_space(t_param *storage);
int	flag_zero(t_param *storage);
int	flag_hash(t_param *storage, char *hex);
int	general_flags_d(t_param *storage, int nb);
int	general_flags_s(t_param *storage, char *s);
int	general_flags_p(t_param *storage, size_t convert);
int	general_flags_u(t_param *storage, unsigned int nb);
int	general_flags_hex(t_param *storage, char *hex);
int	general_flags_c(t_param *storage, char c);
char	*ft_itoa_sizet(size_t n);


#endif
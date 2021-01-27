/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 09:20:12 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/27 08:26:00 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	char	type;
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		star;
}				t_flags;

int				ft_printf(char const *f, ...);
void			init_flags(t_flags *fs);
int				flag_dot(t_flags *fs, const char *f, int i, va_list args);
void			flag_minus(t_flags *fs);
void			flag_width(t_flags *fs, va_list args);
void			flag_digit(t_flags *fs, char c);
int				ft_istype(char c);
int				ft_isflag(char c);
int				ft_print_spaces(int count);
int				process_char(t_flags *fs, char c);
int				process_percent(t_flags *fs);
int				ft_print_str(const char *s, int count);
int				process_string(t_flags *fs, const char *s);
int				pointer_digits_count(unsigned long p, int base);
int				ft_to_hex_string(unsigned long p, char **s);
int				ft_to_capital_hex_string(unsigned long p, char **s);
int				ft_print_zeros(int count);
int				process_pointer(t_flags *fs, unsigned long p);
int				process_int_positive(t_flags *fs, int count,
				int precision, char *s);
int				process_int_negative(t_flags *fs, int count,
				int precision, char *s);
int				process_int(t_flags *fs, int i);
int				len_process_uint(t_flags *fs, int count,
								int precision, char *s);
int				process_uint(t_flags *fs, unsigned int u);
int				process_hex(t_flags *fs, unsigned int u, int capital);
int				process_type(t_flags *fs, va_list args);
int				parse_flag(t_flags *fs, int i, const char *f, va_list args);
int				process_input(const char *f, va_list args);
int				ft_printf(const char *f, ...);
#endif

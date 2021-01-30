/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:01:42 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 10:41:43 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
//#include <io.h> 
#include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 # include <limits.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putstr_count(char *s, int count);
int		ft_parse_input(const char *s, va_list ap);
int		ft_isdigit(int c);
int		ft_istype(int c);
int		ft_isflag(int c);
size_t	ft_strlen(char *s);
// int		ft_print_space(int count);
// int		ft_print_zero(int count);
char	*ft_itoa(int n);
char	*ft_strdup(char *s1);
int		ft_space_zero(int count, int c);
typedef	struct	s_list
{
	int			type;
	int 		width;
	int 		minus;
	int 		zero;
	int 		dot;
	int 		star;
}				t_list;

int 	flag_dot(const char *s, int i, t_list *flags, va_list ap);
void 	flag_width(t_list *flags, va_list ap);
void	flag_digit(t_list *flags, char s);


int		proc_char(t_list *flags, char c);
int		proc_string(t_list *flags, char *s);
int   	proc_pointer(t_list *flags, unsigned long i);
int    	proc_hex(t_list *flags, unsigned long i, int cap);
int		proc_percent(t_list *flags);
int		proc_int(t_list *flags, int i);
int		proc_uint(t_list *flags, unsigned int u);
char	*ft_utoa(unsigned int n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
#endif
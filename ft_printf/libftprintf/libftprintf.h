/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:01:42 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 14:45:52 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
//#include <io.h> 
#include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_parse_input(const char *s, va_list ap);
void	check_space(const char *s, int *i, int *len);
int		ft_isdigit(int c);
int		ft_istype(int c);
int		ft_isflag(int c);
size_t	ft_strlen(char *s);
int		ft_print_spaces(int count);
int		ft_print_str(char *s, int count);

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

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:01:42 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/23 13:35:16 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
//#include <io.h> 
 #include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
int		ft_parse_input(const char *s, va_list ap);
void	check_space(const char *s, int *i, int *len);
int		ft_isdigit(int c);
int		ft_istype(int c);
int		ft_isflag(int c);



typedef	struct	s_list
{
	int			type;
	int 		width;
	int 		minus;
	int 		zero;
	int 		dot;
	int 		flags;
}				t_list;

#endif
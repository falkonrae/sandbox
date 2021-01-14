/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:01:42 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/14 13:50:51 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <io.h> 
// #include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);



typedef	struct	s_list
{
	char		type;
	int 		width;
	int 		minus;
	int 		zero;
	int 		precision;
	int 		star;
	int 		flags;
}				t_list;

#endif
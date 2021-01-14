/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:03:17 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/14 13:59:34 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

gi
int 	ft_printf(const char *s, ...)
{
	va_list		ap;
	char *name;
	char buf;
	unsigned int days;
	t_list info;
	va_start(ap, s);
	
	name = va_arg(ap, char*);
	days = va_arg(ap, unsigned int);
	while (*s != '\0')
	{
		if (*s != '%')
			ft_putchar(*s);
		if (*s == '%')
		{
			s++;
			if (*s == 'u')
				ft_putnbr(days);
			else if (*s == 's')
				ft_putstr(name);
		}
		s++;
	}
	va_end(ap);
	return(0);
}

int main()
{
	char* name = "Anna";
	unsigned int days = 7;
	ft_printf("Hello %s! The deadline is in %u days.\n", name, days);
}
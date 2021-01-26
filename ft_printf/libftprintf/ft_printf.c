/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:03:17 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 14:50:53 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	ft_printf(const char *s, ...)
{
	int			len;
	t_list		check;
	va_list		ap;

	va_start(ap, s);
	len = ft_parse_input(s, ap);
	va_end(ap);
	return (len);
}


#include <stdio.h>

int		main()
{
	char	*name = "Alian";
	int a;
	int b;

	//unsigned int days = 7;
	a = ft_printf("Hello %.4s! The deadline is in u days.\n", "Aisha");
	printf("\n");
	b = printf("Hello %.4s! The deadline is in u days.\n", "Aisha");
	printf("\n");
	printf("%d\n", a);
	printf("%d\n", b);
	b = printf("%-p l\n", name);
	printf("%d\n", b);
	ft_printf("%p", "Alian");
	printf("\n");
}

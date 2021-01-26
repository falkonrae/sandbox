/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:03:17 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 11:17:01 by falkonrae        ###   ########.fr       */
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
	char	*name = "";
	int a;
	int b;
	//unsigned int days = 7;
	a = ft_printf("Hello %.4s! The deadline is in u days.\n", "Aisha");
	printf("\n");
	b = printf("Hello %.4s! The deadline is in u days.\n", "Aisha");
	printf("\n");
	printf("%d\n", a);
	printf("%p\n", name);
	ft_printf("%p", name);
	printf("\n");
	printf("%d\n", b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:03:17 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/25 10:55:20 by falkonrae        ###   ########.fr       */
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
	char	name = 'A';
	int a;
	int b;
	//unsigned int days = 7;
	//a = ft_printf("Hello %0c ! The deadline is in u days.\n", name);
	printf("\n");
	printf("Hello %55d ! The deadline is in u days.\n", 4345);
	printf("\n");
	printf("%d\n", a);
	printf("%d\n", a);
}

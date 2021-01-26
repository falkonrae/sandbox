/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:03:17 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 20:03:55 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	ft_printf(const char *s, ...)
{
	int			len;
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
	a = ft_printf("Hello %044s! The deadline is in u days.\n", "Aisha");
	b = printf("Hello %044s! The deadline is in u days.\n", "Aisha");
	printf("%d\n", a);
	printf("%d\n", b);
		printf("\n");
	b = printf("%044p l\n", "AISHA");
	a = ft_printf("%044p l\n", "AISHA");
	printf("%d\n", b);
	printf("%d\n", a);
	// printf("\n6gfffgg");
	// printf("\n6ggg");
	
}

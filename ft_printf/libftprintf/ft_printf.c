/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:03:17 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/23 10:39:20 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	ft_printf(const char *s, ...)
{
	int			lenght;
	t_list		check;
	va_list		ap;

	va_start(ap, s);
	lenght = ft_parce_input(s, ap);
	va_end(ap);
	return (0);
}


// #include <stdio.h>

// int		main()
// {
// 	char	*name = "Anna";
// 	unsigned int days = 7;
// 	ft_printf("Hello %s! The deadline is in %u days.\n", name, days);
// }

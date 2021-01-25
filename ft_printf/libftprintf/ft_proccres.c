/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proccres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/25 10:49:03 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

//proc_string(flags, va_arg(ap, char *)

int		proc_char(t_list *flags, char c)
{
	int len;

	len = 1;
	if (flags->minus)
		ft_putchar(c);
	while (len < flags->width)
	{
		ft_putchar(' ');
		len++;
	}
	if (!flags->minus)
		ft_putchar(c);
	return (len);
}
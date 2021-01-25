/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/25 10:06:49 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


void		flag_digit(t_list *flags, char s)
{
	if (flags->star == 1)
		flags->width = 0;
	else
		flags->width = flags->width * 10 + (s - '0');
}

void 	flag_width(t_list *flags, va_list ap)
{
	flags->star = 1;
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= (-1);
		flags->zero = 0;
	}
}

int 	flag_dot(const char *s, int i, t_list *flags, va_list ap)
{
	i++;
	if (s[i] == '*')
	{
		flags->dot = va_arg(ap, int);
		i++;
	}
	if (s[i] != '*')
	{
		flags->dot = 0;
		while (ft_isdigit(s[i]))
		{
			flags->dot = flags->dot * 10 + (s[i] - '0');
			i++;
		}
	}
	return (i);
}

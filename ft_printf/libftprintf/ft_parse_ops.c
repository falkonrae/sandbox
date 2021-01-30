/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 17:53:00 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_istype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		ft_isflag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}

void	flag_digit(t_list *flags, char s)
{
	if (flags->star == 1)
		flags->width = 0;
	else
		flags->width = flags->width * 10 + (s - '0');
}

void	flag_width(t_list *flags, va_list ap)
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

int		flag_dot(const char *s, int i, t_list *flags, va_list ap)
{
	flags->dot = 0;
	i++;
	if (s[i] == '*')
	{
		flags->dot = va_arg(ap, int);
		if (flags->dot < 0)
			flags->dot = -1;
		i++;
	}
	else
	{
		while (ft_isdigit(s[i]))
		{
			flags->dot = flags->dot * 10 + (s[i] - '0');
			i++;
		}
	}
	return (i);
}

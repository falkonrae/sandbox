/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:53:01 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:25:05 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isflag(char c)
{
	return (c == '.' || c == '-' || c == '*');
}

int		flag_dot(t_flags *fs, const char *f, int i, va_list args)
{
	fs->precision = 0;
	i++;
	if (f[i] == '*')
	{
		fs->precision = va_arg(args, int);
		if (fs->precision < 0)
			fs->precision = -1;
		i++;
	}
	else
	{
		while (ft_isdigit(f[i]))
		{
			fs->precision = fs->precision * 10 + (f[i] - '0');
			i++;
		}
	}
	return (i - 1);
}

void	flag_minus(t_flags *fs)
{
	fs->minus = 1;
	fs->zero = 0;
}

void	flag_width(t_flags *fs, va_list args)
{
	fs->star = 1;
	fs->width = va_arg(args, int);
	if (fs->width < 0)
	{
		fs->minus = 1;
		fs->width = fs->width * -1;
		fs->zero = 0;
	}
}

void	flag_digit(t_flags *fs, char c)
{
	if (fs->star == 1)
		fs->width = 0;
	else
		fs->width = fs->width * 10 + (c - '0');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:48:32 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/23 12:39:49 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			ft_putchar(*(s++));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

// void		check_space(const char *s, int *i, int *len)
// {
// 	*i += 1;
// 	while (s[*i] == ' ')
// 	{
// 		*i += 1;
// 		*len += 1;
// 	}
// }   для бонусов

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_istype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
	|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_isflag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}
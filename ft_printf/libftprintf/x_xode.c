/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_xode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:47:11 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/14 13:54:22 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>

// void	ft_putnbr(int n)
// {
// 	if (n == -2147483648)
// 	{
// 		ft_putstr("-2");
// 		n = 147483648;
// 	}
// 	if (n < 0)
// 	{
// 		ft_putchar('-');
// 		n = -n;
// 	}
// 	if (n > 9 && n <=16)
// 		ft_putchar(n % 16 + 'A');
// 	if (n > 16)
// 	{
// 		ft_putnbr(n / 16);
// 		ft_putchar(n % 16 + '0');
// 	}
// 	else
// 		ft_putchar(n + '0');
// }

size_t lenght_of_number(int a)
{
	int i;
	i = 0;
	while (a >= 16)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

int main()
{
	int a = 2336;
	int b;
	size_t i;
	i = lenght_of_number(a);
	
	char c[lenght_of_number(a)];
	
	while (b >= 16)
	{
		b = a % 16;
		a = a / 16;
		if (b > 9 && b <=16)
			c[i] = b + 'A';
		else
			c[i] = b + '0';
		i--;
	}
	if (a > 9 && b <=16)
			c[i] = b + 'A';
		else
			c[i] = b + '0';
	
	printf("mine = %s\n", c);
	printf("right = %x", 2336);
}

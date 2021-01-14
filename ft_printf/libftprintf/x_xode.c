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

#include "libftprintf.h"

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
	if (n > 9 && n <=16)
		ft_putchar(n % 10 + '101');
	if (n > 16)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int main()
{
	int a = 2336;
	int b;
	int i = 0;
	b = a;
	char *c;
	while (a >= 16)
	{
		a = a / 16;
		i++;
	}
	while (b >= 16)
	{
		b = a % 16;
		a = a / 16;
		c[i] = b + '0';
		i--;
	}
	c[i] = a + '0';
	j = i;
	d = malloc(sizeof(char) * i);
	
	
	printf("mine = %s\n", c);
	printf("right = %x", 2336);
}

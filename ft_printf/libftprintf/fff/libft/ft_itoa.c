/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:57:03 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:33:36 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_number(int n)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	fill_digits(int i, int n, char *s)
{
	int min_i;

	min_i = 0;
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
		min_i = 1;
	}
	while (i >= min_i)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = digits_number(n);
	if (n < 0)
		i++;
	if (!(s = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	s[i] = '\0';
	i--;
	fill_digits(i, n, s);
	return (s);
}

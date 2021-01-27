/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:57:03 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:32:38 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	u_digits_number(unsigned int n)
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

static void	u_fill_digits(int i, unsigned int n, char *s)
{
	int min_i;

	min_i = 0;
	while (i >= min_i)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

char		*ft_utoa(unsigned int n)
{
	char	*s;
	int		i;

	i = u_digits_number(n);
	if (!(s = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	s[i] = '\0';
	i--;
	u_fill_digits(i, n, s);
	return (s);
}

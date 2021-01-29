/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:56:34 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/29 14:49:01 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		n_size(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*new_str(char *str, int nlen, int neg, int n)
{
	while (nlen >= 0)
	{
		if (nlen == 0 && neg == 1)
		{
			str[0] = '-';
			nlen--;
		}
		else
		{
			str[nlen] = (n % 10) + '0';
			nlen--;
			n = n / 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	nlen = n_size(n);
	str = (char *)malloc(sizeof(char) * (nlen + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str[nlen] = '\0';
	nlen--;
	return (new_str(str, nlen, neg, n));
}

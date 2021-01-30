/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:56:34 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 19:18:00 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*new_str_u(char *str, int nlen, unsigned int n)
{
	while (nlen >= 0)
	{
		if (n < 0)
			n = -n;
		str[nlen] = (n % 10) + '0';
		n = n / 10;
		nlen--;
	}
	return (str);
}

int		n_size_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		nlen;

	if (n == UINT_MAX)
		return (ft_strdup("4294967295"));
	nlen = n_size_u(n);
	if (!(str = (char *)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	str[nlen] = '\0';
	nlen--;
	return (new_str_u(str, nlen, n));
}

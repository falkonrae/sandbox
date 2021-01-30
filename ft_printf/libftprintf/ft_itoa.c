/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:56:34 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 10:37:38 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(char) * len);
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}


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

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	neg = 0;
	nlen = n_size(n);
	if(!(str = (char *)malloc(sizeof(char) * (nlen + 1))))
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


char		*ft_utoa(unsigned int n)
{
	char	*str;
	int		nlen;

	nlen = n_size(n);
	if(!(str = (char *)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	str[nlen] = '\0';
	nlen--;
	return (new_str(str, nlen, 0, n));
}
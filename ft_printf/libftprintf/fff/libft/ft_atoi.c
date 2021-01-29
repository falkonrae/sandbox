/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:40:20 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/16 13:18:12 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
	|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	return (i);
}

static int	ft_get_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		(*i)++;
	}
	return (sign);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;
	int add;
	int nbr;

	i = ft_skip_spaces(str);
	sign = ft_get_sign(str, &i);
	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		add = str[i] - '0';
		if (sign == 1 && add > INT_MAX - nbr * 10)
			return (-1);
		if (sign == -1 && add < INT_MIN + nbr * 10)
			return (1);
		nbr = nbr * 10 + add;
		i++;
	}
	return (sign * nbr);
}

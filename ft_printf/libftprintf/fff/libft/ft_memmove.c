/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:33:07 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:30:46 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_forward(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void		ft_back(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t i;

	i = 1;
	while (i <= n)
	{
		d[n - i] = s[n - i];
		i++;
	}
}

void			*ft_memmove(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dst;
	if (src == dst || n == 0)
	{
		return (dst);
	}
	if (src > dst)
		ft_forward(d, s, n);
	else
		ft_back(d, s, n);
	return (dst);
}

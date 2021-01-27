/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:12:06 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/12 12:44:28 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;
	unsigned char		cc;

	i = 0;
	s = (const unsigned char*)src;
	d = (unsigned char*)dst;
	cc = (unsigned char)c;
	while (i < n && s[i] != cc)
	{
		d[i] = s[i];
		i++;
	}
	if (i == n)
	{
		return (NULL);
	}
	else
	{
		d[i] = s[i];
	}
	return ((void*)&d[i + 1]);
}

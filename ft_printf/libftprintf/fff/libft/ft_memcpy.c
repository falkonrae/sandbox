/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:39:21 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/13 16:42:32 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char *s;
	unsigned char		*d;

	i = 0;
	s = (const unsigned char*)src;
	d = (unsigned char*)dst;
	if (src == 0 && dst == 0)
	{
		return (dst);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

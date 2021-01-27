/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:12:58 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:31:28 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(s) + 1;
	while (i < len && s[i] != c)
	{
		i++;
	}
	if (i == len)
	{
		return (NULL);
	}
	else
	{
		return ((char *)&s[i]);
	}
}

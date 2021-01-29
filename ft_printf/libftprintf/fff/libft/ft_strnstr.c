/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:16:11 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/19 13:11:52 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (needle[0] == '\0')
		return ((char*)haystack);
	if (haystack[0] == '\0' || len == 0)
	{
		return (NULL);
	}
	i = 0;
	needle_len = ft_strlen(needle);
	if (len < needle_len)
	{
		return (NULL);
	}
	while (i < len - needle_len + 1)
	{
		if (ft_memcmp(&haystack[i], needle, needle_len) == 0)
		{
			return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

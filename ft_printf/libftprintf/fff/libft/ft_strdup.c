/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:03:23 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/06 11:34:40 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ss;

	len = ft_strlen(s1);
	ss = (char*)malloc((len + 1) * (sizeof(char)));
	if (ss == NULL)
	{
		return (NULL);
	}
	ft_memcpy(ss, s1, len + 1);
	return (ss);
}

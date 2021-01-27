/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:19:21 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/13 15:42:57 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	int		size_l;
	char	*ss;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_l = ft_strlen(s1) + ft_strlen(s2);
	ss = (char*)(malloc((size_l + 1) * sizeof(char)));
	if (ss == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ss[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		ss[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	ss[ft_strlen(s1) + i] = '\0';
	return (ss);
}

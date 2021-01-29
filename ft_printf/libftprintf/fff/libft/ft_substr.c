/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:19:13 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/13 15:19:17 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ss;

	i = 0;
	if (s == NULL)
		return (NULL);
	ss = (char*)malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ss[0] = '\0';
		return (ss);
	}
	while (i < len && s[start + i] != '\0')
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}

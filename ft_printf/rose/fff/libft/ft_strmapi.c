/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:12:18 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/13 16:01:50 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ss;
	int		i;

	if (s == NULL)
		return (NULL);
	ss = ft_strdup(s);
	if (ss == NULL)
		return (NULL);
	i = 0;
	while (ss[i] != '\0')
	{
		ss[i] = (*f)(i, ss[i]);
		i++;
	}
	return (ss);
}

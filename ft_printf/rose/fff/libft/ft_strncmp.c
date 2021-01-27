/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 12:10:27 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/09 17:05:55 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (i < n)
	{
		if (ss1[i] == '\0' && ss2[i] != '\0')
			return (-1);
		if (ss1[i] == '\0' && ss2[i] == '\0')
			return (0);
		if (ss2[i] == '\0')
			return (1);
		if (ss1[i] != ss2[i])
		{
			return ((int)ss1[i] - ss2[i]);
		}
		i++;
	}
	return (0);
}

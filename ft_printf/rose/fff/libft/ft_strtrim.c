/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:33:49 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/19 13:15:02 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	if (set[0] == '\0' || s1[0] == '\0')
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= i && ft_strchr(set, s1[j]) != NULL)
	{
		j--;
	}
	return (ft_substr(s1, i, j - i + 1));
}

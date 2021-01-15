/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:29:07 by wtahm             #+#    #+#             */
/*   Updated: 2020/12/05 21:54:33 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s) + 1;
	while (i < len && s[i] != c)
		i++;
	if (i == len)
		return (NULL);
	else
		return (&s[i]);
}

void	ft_strlcpy(char *dst, char *src)
{
    size_t  i;

    i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*ss;

	size1 = 0;
	if (s1)
		size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ss = (char*)(malloc((size1 + size2 + 1) * sizeof(char)));
	if (ss)
	{
		if (s1)
			ft_strlcpy(ss, s1);
		ft_strlcpy(ss + size1, s2);
		ss[size1 + size2] = '\0';
	}
	if (s1)
		free(s1);
	free(s2);
	return (ss);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ss;
	size_t	i;

	len = ft_strlen(s);
	ss = (char*)malloc((len + 1) * sizeof(char));
	if (ss == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ss[i] = s[i];
		i++;
	}
	return (ss);
}
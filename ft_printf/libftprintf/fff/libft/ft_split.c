/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:47:48 by wtahm             #+#    #+#             */
/*   Updated: 2020/11/19 13:07:57 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int count;

	count = 0;
	while (1)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			return (count);
		count++;
		while (*s != c && *s != '\0')
			s++;
	}
}

static int	ft_word_length(const char *s, char c)
{
	int length;

	length = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}

static void	*ft_free_strs(char **ss)
{
	while (*ss != NULL)
	{
		free(*ss);
		ss++;
	}
	free(ss);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	int			i;
	char		**ss;
	int			word_length;

	if (s == NULL)
		return (NULL);
	ss = ((char**)ft_calloc((ft_count_words(s, c) + 1), sizeof(char*)));
	if (ss == NULL)
		return (NULL);
	i = 0;
	while (1)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			return (ss);
		word_length = ft_word_length(s, c);
		ss[i] = (((char*)ft_calloc(word_length + 1, sizeof(char))));
		if (ss[i] == NULL)
			return (ft_free_strs(ss));
		ft_strlcpy(ss[i], s, word_length + 1);
		i++;
		s = s + word_length;
	}
}

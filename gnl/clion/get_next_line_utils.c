/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:45:14 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/21 15:45:15 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
void			*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	i;

	i = -1;
	if (!(temp = malloc(count * size)))
		return (NULL);
	if (!count || !size)
		return (temp);
	while (++i < count * size)
		((unsigned char *)temp)[i] = '\0';
	return (temp);
}

*/




/*
char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
*/
// char	*ft_strchr(char *s, int c)
// {
// 	char	*mas;
// 	char	sym;
// 	int		i;

// 	i = 0;
// 	mas = (char *)s;
// 	sym = (char)c;
// 	while (mas[i] != '\0')
// 	{
// 		if (mas[i] == sym)
// 			return (&mas[i]);
// 		i++;
// 	}
// 	if (mas[i] == sym)
// 		return (&mas[i]);
// 	return (NULL);
// }
char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(tab = malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		while (s1[i])
		{
			tab[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			tab[i + j] = s2[j];
			j++;
		}
		free(s1);
		tab[i + j] = '\0';
		return (tab);
	}
	return (NULL);
}

// char		*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	unsigned int	i;
// 	char			*str;

// 	i = 0;
// 	if (!s || (start + len > ft_strlen(s)))
// 		return (str = ft_strdup("\0"));
// 	if (!(str = malloc(sizeof(char) * (len + 1))))
// 		return (NULL);
// 	while (i < len)
// 	{
// 		str[i] = s[start + i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (sub == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	while (i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
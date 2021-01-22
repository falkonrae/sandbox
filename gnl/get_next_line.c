/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:59:30 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/21 17:16:34 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *buf;

	buf = (unsigned char *)s;
	while (n > 0)
	{
		*buf = '\0';
		buf++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (int *)malloc(size * count);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char	*check_ost(char *ost, int i)
{
	char			*buf;

	if (ost[i])
	{
		buf = ft_strdup(ost + i + 1);
		free(ost);
	}
	else
	{
		free(ost);
		buf = NULL;
	}
	return (buf);
}

int		memory_free(int ret, char **readed, char **ost)
{
	if (ret >= 0 && (*readed || *ost))
	{
		if (*readed)
			free(*readed);
		if (ret == 0 && *ost)
			free(*ost);
	}
	if (ret == -1)
	{
		if (!*readed)
			free(*readed);
		if (*ost)
			free(*ost);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*readed;
	int				ret;
	int				i;

	if (!ost)
		ost = (char *)ft_calloc(sizeof(char), 1);
	if (BUFFER_SIZE <= 0 || !line || fd < 0 ||
	!(readed = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (-1);
	while (!(ft_strchr(readed, '\n')) && (ret = read(fd, readed, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (memory_free(-1, &readed, &ost));
		readed[ret] = '\0';
		ost = ft_strjoin(ost, readed);
	}
	i = 0;
	while (ost[i] && ost[i] != '\n')
		i++;
	*line = ft_substr(ost, 0, i);
	ost = check_ost(ost, i);
	if (ret || ost)
		return (memory_free(1, &readed, &ost));
	return (memory_free(0, &readed, &ost));
}

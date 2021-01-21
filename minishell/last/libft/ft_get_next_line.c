/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:24:24 by rqouchic          #+#    #+#             */
/*   Updated: 2020/12/24 16:56:56 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

int		ft_stop(char **buff, char **prev, char **next, int res)
{
	if (buff)
		if (*buff)
		{
			free(*buff);
			*buff = NULL;
		}
	if (prev)
		if (*prev)
		{
			free(*prev);
			*prev = NULL;
		}
	if (next)
		if (*next)
		{
			free(*next);
			*next = NULL;
		}
	return (res);
}


int		is_in_str(const char *str, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (!ft_strlen(to_find))
		return (i);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (i);
		}
		i++;
	}
	return (i);
}

int		get_line(int fd, char **str)
{
	int		res;
	char	*buff;
	char	*tmp;

	if (!(buff = malloc(sizeof(*buff) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((res = read(fd, buff, BUFFER_SIZE)) == -1)
		return (ft_stop(&buff, NULL, NULL, -1));
	buff[res] = '\0';
	ft_stop(str, NULL, NULL, 0);
	if (!(*str = ft_strdup(buff)))
		return (ft_stop(&buff, NULL, NULL, -1));
	while (is_in_str(buff, "\n") == BUFFER_SIZE && res != 0)
	{
		if ((res = read(fd, buff, BUFFER_SIZE)) == -1)
			return (ft_stop(&buff, NULL, NULL, -1));
		buff[res] = '\0';
		if (!(tmp = ft_strjoin(*str, buff)))
			return (ft_stop(&buff, NULL, NULL, -1));
		free(*str);
		*str = tmp;
	}
	return (ft_stop(&buff, NULL, NULL, (res < BUFFER_SIZE && is_in_str(buff,
						"\n") == res ? 0 : res)));
}

int		complet_line(char **buff, char **str, char **line)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if ((buff[0][(i = is_in_str(*buff, "\n") + 1) - 1]) == 0)
	{
		*str = ft_strdup("");
		return (0);
	}
	j = is_in_str(&buff[0][i], "\n");
	if (!(*str = malloc(sizeof(**str) * j + 1)))
		return (-1);
	ft_strlcpy(*str, &buff[0][i], j + 1);
	if (buff[0][i + j] == '\n')
	{
		tmp = ft_strdup(&buff[0][i + j]);
		free(*buff);
		*buff = tmp;
		return (-2);
	}
	free(*line);
	*line = ft_strdup(&buff[0][i]);
	return (0);
}

int		join_line(char **line, char **new_line, const char *str, char **prev)
{
	size_t	max;
	char	*tmp;

	if (!str)
	{
		*line = *new_line;
		free(*prev);
		*prev = ft_strdup(*line);
		return (1);
	}
	max = is_in_str(str, "\n");
	if (max > 0)
	{
		if (!(tmp = malloc(sizeof(*tmp) * (max + 1))))
			return (0);
		ft_strlcpy(tmp, str, max + 1);
		*line = ft_strjoin(*new_line, tmp);
		free(tmp);
	}
	else
		*line = ft_strdup(*new_line);
	free(*new_line);
	free(*prev);
	*prev = strdup(*line);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	static char	*buff;
	static char *prev;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	res = 0;
	new_line = NULL;
	if (buff)
		if ((res = complet_line(&buff, &new_line, &prev)) == -2)
			return (join_line(line, &new_line, NULL, &prev));
	if (res == -1)
		return (ft_stop(&buff, &prev, NULL, -1));
	if (!new_line)
		new_line = strdup("");
	if ((res = get_line(fd, &buff)) == -1)
		return (ft_stop(&buff, &prev, &new_line, -1));
	if (buff[0] != '\0')
		if (!(join_line(line, &new_line, buff, &prev)))
			return (ft_stop(&buff, &prev, &new_line, -1));
	if (buff[0] == '\0')
		*line = new_line;
	return (res > 0 ? 1 : ft_stop(&buff, &prev, NULL, 0));
}
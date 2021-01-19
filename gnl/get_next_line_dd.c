/*#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)c;
	while (*s)
	{
		if (*s == cc)
			return ((char*)s);
		s++;
	}
	if (*s == cc)
		return ((char*)s);
	return ((char*)NULL);
}

char	*ft_save(char *buf, char *ost)
{
	char *copy;

	if (ost)
	{
		copy = ft_strjoin(ost, buf);
		free(ost);
		ost = ft_strdup(copy);
		free(copy);
	}
	else
		ost = ft_strdup(buf);
	return (ost);
}

char	*ft_check_line(char *ost, char **line, int readed_byte)
{
	unsigned int	i;
	char			*copy;

	i = 0;
	while (ost[i])
	{
		if (ost[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(ost))
	{
		*line = ft_substr(ost, 0, i);
		copy = ft_substr(ost, i + 1, ft_strlen(ost));
		free(ost);
		ost = ft_strdup(copy);
		free(copy);
	}
	else if (readed_byte == 0)
	{
		*line = ost;
		ost = NULL;
	}
	return (ost);
}

int		retreaded_byte(char **ost, int fd)
{
	char	*buf;
	int		readed_byte;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(*ost, '\n') && (readed_byte = read(fd, buf, BUFFER_SIZE)))
	{
		if (readed_byte == -1)
		{
			free(buf);
			buf = NULL;
			return (-1);
		}
		buf[readed_byte] = '\0';
		*ost = ft_save(buf, *ost);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (readed_byte);
}

int		get_next_line(int fd, char **line)
{
	static char	*ost[4096];
	int			readed_byte;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!ost[fd] && !(ost[fd] = ft_strdup("")))
		return (-1);
	if ((readed_byte = retreaded_byte(&ost[fd], fd)) == -1)
		return (-1);
	if (readed_byte <= 0 && !ost[fd])
	{
		*line = ft_strdup("");
		return (readed_byte);
	}
	ost[fd] = ft_check_line(ost[fd], line, readed_byte);
	if (readed_byte <= 0 && !ost[fd])
		return (readed_byte);
	return (1);
}

*/

#include "get_next_line.h"

int					memory_free(char **s, char **s2)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (-1);
}

char				*chk_ost(char *ost, char **line)
{
	char			*nline;

	nline = NULL;
	if (ost)
	{
		if ((nline = ft_strchr(ost, '\n')))
		{
			*nline = '\0';
			*line = ft_strdup(ost);
			nline++;
			ft_strcpy(ost, nline);
		}
		else
			*line = ft_strdup(ost);
	}
	else
		*line = ft_strdup("");
	return (nline);
}

void				do_if(char **buf, char **nline, char **ost)
{
	if ((*nline = ft_strchr(*buf, '\n')))
	{
		**nline = '\0';
		(*nline)++;
		free(*ost);
		*ost = ft_strdup(*nline);
	}
}

int					get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	char			*nline;
	int				n;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	n = 1;
	nline = chk_ost(ost, line);
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (memory_free(&buf, line));
	while (!nline && (n = read(fd, buf, BUFFER_SIZE)))
	{
		if (n < 0)
		{
			return (memory_free(&ost, &buf));
		}
		buf[n] = '\0';
		do_if(&buf, &nline, &ost);
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	if (n == 0 && ost != 0)
		memory_free(&ost, &ost);
	return (n || nline) ? 1 : 0;
}

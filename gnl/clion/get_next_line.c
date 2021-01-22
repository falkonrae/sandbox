// #include <stdio.h>
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

void		*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = (int *)malloc(size * count);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char		*check_ost(char *ost, int i)
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

int			memory_free(int ret, char **reading, char **ost)
{
	if (ret >= 0 && (*reading || *ost))
	{
		if (*reading)
			free(*reading);
		if (ret == 0 && *ost)
			free(*ost);
	}
	if (ret == -1)
	{
		if (!*reading)
			free(*reading);
		if (*ost)
			free(*ost);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*reading; 
	int				ret; 
	int				i;

	if (!ost)
		ost = (char *)ft_calloc(sizeof(char), 1);
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
			return (memory_free(-1, &reading, &ost));
	if (!(reading = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return(-1);
	while (!(ft_strchr(reading, '\n')) && (ret = read(fd, reading, BUFFER_SIZE))) 
	{
		if (ret == -1)
			return (memory_free(-1, &reading, &ost));
		reading[ret] = '\0'; 
		ost = ft_strjoin(ost, reading); 
	}
	i = 0;
	while (ost[i] && ost[i] != '\n') 
		i++;
	*line = ft_substr(ost, 0, i);
	ost = check_ost(ost, i); 
	if (ret || ost)
		return (memory_free(1, &reading, &ost));
	return (memory_free(0, &reading, &ost));
}

int main()
{
	int		fd = open("text.txt", O_RDONLY);
	char	*line;
	if (!(line= (char *)malloc(sizeof(char))))
		return (0);
	while (get_next_line(fd, &line))
	{
    printf("string - %s\n", line);
	}
	// get_next_line(fd, &line);
    // printf("1 string - %s1\n", line);
    
    // get_next_line(fd, &line);
    // printf("%s2\n", line);

    // get_next_line(fd, &line);
    // printf("%s3\n", line);

	// get_next_line(fd, &line);
    // printf("%s4\n", line);
	free (line);
	return (0);
}

// int main()
// {
// 	while (1)
// 	{

// 	}
// 	return 0;
// }
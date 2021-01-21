#include <stdio.h>
#include "get_next_line.h"

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
	static char		*ost; // сюда кладется строка, получаемая в процессе стрджоина
	char			*reading; // сюда кладется временно то, что мы считывыаем
	int				ret; // количество прочитанных байт
	int				i;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 ||
		!(reading = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		//reading = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1)
		return (memory_free(-1, &reading, &ost));
	if (!ost)
		ost = malloc(sizeof(char));
		//ost = (char *)ft_calloc(sizeof(char), 1);
	while (!ft_strchr(reading, '\n') && (ret = read(fd, reading, BUFFER_SIZE)))  //здесь записывается в буфер считанные байты и в рет кладется количество прочитанных байт
	{
		if (ret == -1)
			return (memory_free(-1, &reading, &ost));
		reading[ret] = '\0'; // пока не встретилось слэш н, ставим конец строки на расстояние ретурна.
		printf("\e[1;92mbuf = %s\n\e[0m", reading);
		ost = ft_strjoin(ost, reading); // в ост прибавляем
		printf("\e[1;34most = %s\n\e[0m", ost);
	}
	i = 0;
	while (ost[i] && ost[i] != '\n') //здесь считаем, сколько байтов надо записать до того, пока не встретим н
		i++;
	*line = ft_substr(ost, 0, i);
	printf("\e[1;93mline = %s\n\e[0m", *line); // в лайн записываем нашу получившуюся строку без символов после н
	ost = check_ost(ost, i); // проверяем остаток, если он больше нуля.
	if (ret || ost)
		return (memory_free(1, &reading, &ost));
	return (memory_free(0, &reading, &ost));
}

int main()
{
	int		fd = open("text.txt", O_RDONLY);
	char	*line;
	
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
	
	return (0);
}
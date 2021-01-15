#include "get_next_line.h"

int     get_next_line(int fd, char **line)
{
	static char *reminder;   
    char        *buffer;
    ssize_t     bytes_read;

	if (fd < 0 || line == NULL)
        return (-1);
	buffer = NULL;
	if (reminder)
		buffer = reminder;
	*line = NULL;
	while (1)
	{
		if (!buffer)
		{
			buffer = (char*)(malloc((BUFFER_SIZE + 1) * sizeof(char)));
			if (buffer == NULL)
				return (-1);
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				return (bytes_read);
			buffer[bytes_read] = '\0';
		}
		reminder = ft_strchr(buffer, '\n');
		if (reminder == NULL)
		{
			*line = ft_strjoin(*line, buffer);
			if (!*line)
				return (-1);
			buffer = NULL;
		}
		else
		{
			*reminder = '\0';
			reminder = ft_strdup(reminder+1);
			if (!reminder)
			{
				free(buffer);
				return (-1);
			}
			*line = ft_strjoin(*line, buffer);
			if (!*line)
				return (-1);
			return (1);
		}
	}
}

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int	main(int argc, char **argv)
// {
// 	char	*line;
// 	int		read_res;
// 	int 	i;

// 	if (argc != 2)
// 		return (1);

// 	int fd = 0;//open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 		return (fd);
	
// 	i = 0;
// 	while (1)
// 	{
// 		read_res = get_next_line(fd, &line);
// 		if (read_res == -1)
// 			return (2);
// 		printf("%d: %s\n", i, line);
// 		if (read_res == 0)
// 			return (0);
// 		i++;
// 	}
// }
#include "get_next_line.h"
static int          read_buffer(const int fd, char **buffer, char **line)
{
    ssize_t     bytes_read;
    if (*buffer == NULL)
    {
        *buffer = (char*)(malloc((BUFFER_SIZE + 1) * sizeof(char)));
        if (*buffer == NULL)
            return (-1);
        bytes_read = read(fd, *buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
        {
            free(*buffer);
            if (bytes_read == 0 && *line == NULL)
                *line = ft_strdup("");
            return ((int)bytes_read);
        }
        (*buffer)[bytes_read] = '\0';
    }
    return (1);
}
static int          process_buffer_with_new_line(char **ostatok, char **buffer,
char **line)
{
    **ostatok = '\0';
    if (*(*ostatok + 1) != '\0')
    {
        *ostatok = ft_strdup(*ostatok + 1);
        if (*ostatok == NULL)
        {
            free(*buffer);
            return (-1);
        }
    }
    else
        *ostatok = NULL;
    *line = ft_strjoin(*line, *buffer);
    if (*line == NULL)
        return (-1);
    *buffer = NULL;
    return (0);
}
static int          process_buffer(char **ostatok, char **buffer, char **line)
{
    *ostatok = ft_strchr(*buffer, '\n');
    if (*ostatok != NULL)
        return (process_buffer_with_new_line(ostatok, buffer, line));
    else
    {
        *line = ft_strjoin(*line, *buffer);
        *buffer = NULL;
        if (*line == NULL)
            return (-1);
        return (1);
    }
}
int                 get_next_line(int fd, char **line)
{
    static char *ostatok;
    char        *buffer;
    int         res;
    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
        return (-1);
    buffer = NULL;
    if (ostatok != NULL)
        buffer = ostatok;
    ostatok = NULL;
    *line = NULL;
    while (1)
    {
        res = read_buffer(fd, &buffer, line);
        if (res <= 0)
            return (res);
        res = process_buffer(&ostatok, &buffer, line);
        if (res < 0)
            return (-1);
        else if (res == 0)
            return (1);
    }
}
#include <stdio.h>

int main()
{
	int		fd = open("text.txt", O_RDONLY);
	char	*line;
	
	get_next_line(fd, &line);
    printf("%s1\n", line);
    
    get_next_line(fd, &line);
    printf("%s2\n", line);

    get_next_line(fd, &line);
    printf("%s3\n", line);
	
	return (0);
}
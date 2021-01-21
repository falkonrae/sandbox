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
	char			*symb;

	symb = NULL;
	if (ost)
	{
		if ((symb = ft_strchr(ost, '\n')))
		{
			*symb = '\0';
			*line = ft_strdup(ost);
			symb++;
			ft_strcpy(ost, symb);
		}
		else
			*line = ft_strdup(ost);
	}
	else
		*line = ft_strdup("");
	return (symb);
}

// void				do_if(char **buf, char **symb, char **ost)
// {
	
// }

int					get_next_line(int fd, char **line)
{
	static char		*ost;
	char			*buf;
	char			*symb;
	int				n;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	n = 1;
	symb = chk_ost(ost, line);
	
	while (!symb && (n = read(fd, buf, BUFFER_SIZE)))
	{
		if (n < 0)
		{
			return (memory_free(&ost, &buf));
		}
		buf[n] = '\0';
		//do_if(&buf, &symb, &ost);
        if ((symb = ft_strchr(buf, '\n')))
	{
		*symb = '\0';
		(symb)++;
		free(ost);
		ost = ft_strdup(symb);
	}
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	if (n == 0 && ost != 0)
		memory_free(&ost, 0);
	return (n || symb) ? 1 : 0;
}

// #include <stdio.h>

// int main()
// {
// 	int		fd = open("bible.txt", O_RDONLY);
// 	char	*line;
	
// 	// while (get_next_line(fd, &line))
// 	// {
	
//     // printf("%s\n", line);
// 	// }
// 	get_next_line(fd, &line);
//     printf("%s1\n", line);
    
//     get_next_line(fd, &line);
//     printf("%s2\n", line);

//     get_next_line(fd, &line);
//     printf("%s3\n", line);

// 	get_next_line(fd, &line);
//     printf("%s4\n", line);
	
// 	return (0);
// }

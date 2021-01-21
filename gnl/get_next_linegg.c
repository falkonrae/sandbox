/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linegg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:13:35 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/21 07:00:13 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "get_next_line.h"

int free_all(char **buf, char **line)
{
	if (*buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
	if (*line != NULL)
	{
		free(*line);
		*line = NULL;
	}
	return (-1);
}

char *check_ost(char	*ost, char **line)
{
	char *symb;

	symb = NULL;
	if (ost)
	{
		if ((symb = ft_strchr(ost, '\n')))
		{
			*symb = '\0';
			*line = ft_strdup(ost);
			symb++;
			ft_strcpy(ost, ++symb);
		}
		else
			*line = ft_strdup(ost);
	}
	else
		*line = ft_strdup("");
	return (symb);
}

int get_next_line(int fd, char **line)
{
	static char	*ost;
	char 		*buf;
	char 		*symb;
	int 		readed_byte;

	if (!line|| fd < 0 || BUFFER_SIZE <= 0)
	 	return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (free_all(&buf, line));
	symb = check_ost(ost, line);
	while (!symb && ((readed_byte = read(fd, buf, BUFFER_SIZE))))
	{
		if (readed_byte < 0)
			return (free_all(&ost, &buf));
		*symb = '\0';
		if ((symb = ft_strchr(buf, '\n')))
		{
			*symb = '\0';
			symb++;
			free(ost);
			ost = ft_strdup(symb);
		}
		*line = ft_strjoin(*line, buf);
	}
	free (buf);
	if (readed_byte == 0 && ost != 0)
		free_all(&ost, &ost);
	return (readed_byte || symb) ? 1 : 0;
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

	get_next_line(fd, &line);
    printf("%s4\n", line);
	
	return (0);
}
*/

#include "get_next_line.h"

int					memory_free(int ret, char **buf, char **ost)
{
	if (ret >= 0 && (*buf || *ost))
	{
		if (*buf)
			free(*buf);
		if (ret == 0 && *ost)
			free(*ost);
	}
	if (ret == -1)
	{
		if (!*buf)
			free(*buf);
		if (*ost)
			free(*ost);
	}
	return (ret);
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

void				do_if(char **buf, char **symb, char **ost)
{
	if ((*symb = ft_strchr(*buf, '\n')))
	{
		**symb = '\0';
		(*symb)++;
		free(*ost);
		*ost = ft_strdup(*symb);
	}
}

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
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (memory_free(-1, &buf, line));
	while (!symb && (n = read(fd, buf, BUFFER_SIZE)))
	{
		if (n < 0)
		{
			return (memory_free(&ost, &buf));
		}
		buf[n] = '\0';
		do_if(&buf, &symb, &ost);
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	if (n == 0 && ost != 0)
		memory_free(&ost, &ost);
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

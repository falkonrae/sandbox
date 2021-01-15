/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:13:35 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/15 17:08:19 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			ft_strcpy(ost, ++symb);
		}
		else
		{
			*line = ft_strdup(ost);
			ft_strclr(ost);
		}
	}
	else
		*line = ft_new(1);
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
		return (-1);
	symb = check_ost(ost, line);
	while (!symb && ((readed_byte = read(fd, buf, BUFFER_SIZE))))
	{
		if ((symb = ft_strchr(buf, '\n')))
		{
			*symb = '\0';
			symb++;
			ost = ft_strdup(symb);
		}
		buf[BUFFER_SIZE] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	
	return (0);
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
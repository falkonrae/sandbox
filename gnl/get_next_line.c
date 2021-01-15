/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:13:35 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/03 13:32:24 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *check_ost(char	*ost, char **line)
{
	char *s_new;

	s_new = NULL;
	if (ost)
	{
		if (s_new = ft_strchr(ost, '\n'))
		{
			s_new = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++s_new);
		}
		else
		{
			*line = ft_strdup(ost);
			ft_strclr(ost);
		}
	}
	else
		*line = ft_strnew(1);
	return (s_new);
}


int get_next_line(int fd, char **line)
{
	char 		buf[10 + 1];
	char 		*new_s;
	static char	*ost;

	int 	readed_byte;
	new_s = check_ost(ost, line);
	while(!new_s && (readed_byte = read(fd, buf, 10)))
	{
		if (new_s = ft_strchr(buf, '\n'))
		{
			*new_s = '\0';
			new_s++;
			ost = ft_strdup(new_s);
		}
		buf[10] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	
	return (0);
}


#include <stdio.h>

int main()
{
	int		fd = open("text.txt", O_RDONLY);
	char	*line;
	// int 	i;
	// while (i = get_next_line(fd, &line))
	// {
	// 	printf("i = %d %s\n", i, line);
	// 	free(line);
	// }
	//printf("i = %d %s\n", i, line);
	// line = "hello world";
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	// free(line);
	return (0);
}
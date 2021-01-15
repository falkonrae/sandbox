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

int get_next_line(int fd, char **line)
{
	char 		buf[10 + 1];
	char 		*new_s;
	int 		flag;
	static char	*ost;

	flag = 1;
	int 	readed_byte;
	if (ost)
		*line = ft_strdup(ost);
	else
		*line = ft_strnew(1);
	while(flag && (readed_byte = read(fd, buf, 10)))
	{
		if (new_s = ft_strchr(buf, '\n'))
		{
			*new_s = '\0';
			flag = 0;
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
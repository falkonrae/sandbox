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

int get_next_line(int fd, char **line)
{
	
}


#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int		fd = open("file", O_RDONLY);
	char	*line;
	int 	i;
	while (i = get_next_line(fd, &line))
	{
		printf("i = %d %s\n", i, line);
		free(line);
	}
	printf("i = %d %s\n", i, line);
	free(line);
	return (0);
}
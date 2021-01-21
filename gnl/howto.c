# include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
# include <unistd.h>

void			*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	i;

	i = -1;
	if (!(temp = malloc(count * size)))
		return (NULL);
	if (!count || !size)
		return (temp);
	while (++i < count * size)
		((unsigned char *)temp)[i] = '\0';
	return (temp);
}

int main()
{
    int     i = 0;
    int		fd = open("text.txt", O_RDONLY);
    char			*buffer;

    buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
    i = read(fd, buffer, BUFFER_SIZE);
    printf("%d\n", i);
    printf("\e[1;34mbuf = %s\n\e[0m", buffer);
}
#include <stdio.h>

void		check_space(const char *s, int *i, int *len)
{
	*i += 1;
	(*i)++;
	printf("s[*i] = '%c'\n", s[*i]);
	printf("i (before) =  %d\n", *i);
		printf("len (before) =  %d\n", *len);
	while (s[*i] == ' ')
	{
		printf("i =  %d\n", *i);
		printf("len =  %d\n", *len);
		printf("get in \n");
		*i += 1;
		printf("i =  %d\n", *i);
		*len += 1;
		printf("len =  %d\n", *len);
		printf("get out \n");
	}
}

int main()
{
	int i;
	int b;
	char *s = "%  .    hy";
	i = 0;
	b = 5;
	check_space(s, &i, &b);
	printf(" i = %d", i);
	printf("\n b = %d", b);
	return (0);
}
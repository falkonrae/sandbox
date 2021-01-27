#include "libftprintf.h"
#include <stdio.h>

int		main()
{
	char	*name = "Alian";
	int a;
	int b;

	//unsigned int days = 7;
	a = ft_printf("Hello %044s! The deadline is in u days.\n", "Aisha");
	b = printf("Hello %044s! The deadline is in u days.\n", "Aisha");
	printf("%d\n", a);
	printf("%d\n", b);
		printf("\n");
	b = printf("|%15p|\n", NULL);
	a = ft_printf("|%15p|\n", NULL);
	printf("%d\n", b);
	printf("%d\n", a);
	b = printf("|%-8.x|\n", 15000);
	a = ft_printf("|%-8.x|\n", 15000);
	printf("%d\n", b);
	printf("%d\n", a);
	b = printf("|%-5.%|\n");
	a = ft_printf("|%-5.%|\n");
	printf("%d\n", b);
	printf("%d\n", a);
	// printf("\n6gfffgg");
	// printf("\n6ggg");
	
}

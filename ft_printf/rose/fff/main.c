#include "libftprintf.h"
#include <stdio.h>

int		main()
{
	char	*name = "Alian";
	int a;
	int b;

	//unsigned int days = 7;
	// a = ft_printf("Hello %100s! The deadline is in u days.\n", "Aisha");
	// b = printf("Hello %100s! The deadline is in u days.\n", "Aisha");
	// printf("%d\n", a);
	// printf("%d\n", b);
	// 	printf("\n");
	// b = printf("|%15p|\n", name);
	// a = ft_printf("|%15p|\n", name);
	// printf("%d\n", b);
	// printf("%d\n", a);
	// b = printf("|%-8.x|\n", 15000);
	// a = ft_printf("|%-8.x|\n", 15000);
	// printf("%d\n", b);
	// printf("%d\n", a);
	// b = printf("|%32s|\n", "abc");
	// a = ft_printf("|%32s|\n", "abc");
	// printf("%d\n", b);
	// printf("%d\n", a);
	a = printf("|hello, %s.|\n", "gavin");
	b = ft_printf("|hello, %s.|\n", "gavin");
	printf("%d\n", a);
	printf("%d\n", b);
	// printf("\n6gfffgg");
	// printf("\n6ggg");
	
}

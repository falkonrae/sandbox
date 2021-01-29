#include "libftprintf.h"
#include <stdio.h>

int		main()
{
	char	*name = "Alian";
	int a;
	int b;

	//unsigned int days = 7;
	// a = ft_printf("Hello %-33.3s! The deadline is in u days.\n", "Aisha");
	// b = printf("Hello %-33.3s! The deadline is in u days.\n", "Aisha");
	// printf("%d\n", a);
	// printf("%d\n", b);
	// 	printf("\n");
	// b = printf("|%-0155p|\n", name);
	// a = ft_printf("|%-0155p|\n", name);
	// printf("%d\n", b);
	// printf("%d\n", a);
	b = printf("|%00008.X|\n", 15000);
	a = ft_printf("|%00008.X|\n", 15000);
	printf("%d\n", b);
	printf("%d\n", a);
	// b = printf("|%%%%%%|\n");
	// a = ft_printf("|%%%%%%|\n");
	// printf("%d\n", b);
	// printf("%d\n", a);
	// a = printf("|%5s|\n", "goes over");
	// b = ft_printf("|%5s|\n", "goes over");
	// printf("%d\n", a);
	// printf("%d\n", b);
	// printf("\n6gfffgg");
	// printf("\n6ggg");
	// a = printf("|%-5c|\n", 'A');
	// b = ft_printf("|%-5c|\n", 'A');
	// printf("%d\n", a);
	// printf("%d\n", b);
	
}

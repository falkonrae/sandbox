#include "libftprintf.h"
#include <stdio.h>

int		main()
{
	char	*name = "Alian";
	int a;
	int b;

	//unsigned int days = 7;
	// a = ft_printf("Hello %-43.3s! The deadline is in u days.\n", "Aisha");
	// b = printf("Hello %-43.3s! The deadline is in u days.\n", "Aisha");
	// printf("%d\n", a);
	// printf("%d\n", b);
	// 	printf("\n");
	// b = printf("|%5.p|\n", NULL);
	// a = ft_printf("|%5.p|\n", NULL);
	// printf("%d\n", b);
	// printf("%d\n", a);
	// b = printf("|%8.3x|\n", 8375);
	// a = ft_printf("|%8.3x|\n", 8375);
	// printf("%d\n", b);
	// printf("%d\n", a);
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
	// b = printf("|%-.10d|\n", -15000);
	// a = ft_printf("|%-.10d|\n", -15000);
	// printf("%d\n", b);
	// printf("%d\n", a);
	// b = printf("|%.*s|\n", 3, "hello");
	// a = ft_printf("|%.*s|\n", 3, "hello");
	// printf("%d\n", b);
	// printf("%d\n", a);
	// b = printf("|%.*s|\n", 3, "hello");
	// a = ft_printf("|%.*s|\n", 3, "hello");
	// printf("%d\n", b);
	// printf("%d\n", a);
	// b = printf("|%-8.5i|\n", 34);
	// a = ft_printf("|%-8.5i|\n", 34);
	// printf("%d\n", b);
	// printf("%d\n", a);
	b = printf("|this %i number|\n", -267);
	a = ft_printf("|this %i number|\n", -267);
	printf("%d\n", b);
	printf("%d\n", a);
}

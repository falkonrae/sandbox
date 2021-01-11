#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		while (*s)
			ft_putchar(*(s++));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int 	ft_printf(const char *s, ...)
{
	va_list		ap;
	char *name;
	char buf;
	unsigned int days;
	va_start(ap, s);

	name = va_arg(ap, char*);
	days = va_arg(ap, unsigned int);
	while (*s != '\0')
	{
		if (*s != '%')
			ft_putchar(*s);
		if (*s == '%')
		{
			s++;
			if (*s == 'u')
				ft_putnbr(days);
			else if (*s == 's')
				ft_putstr(name);
		}
		s++;
	}
	va_end(ap);
	return(0);
}

int main()
{
	char* name = "Anna";
	unsigned int days = 7;
	ft_printf("Hello %s! The deadline is in %u days.\n", name, days);
}
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int nbrlen(int nbr, int base)
{
	int i = 1;

	while (nbr /= base)
		i++;
	return (i);
}

void	ft_putnbr(long nbr, int base, char *b)
{
	if (nbr >= base)
		ft_putnbr(nbr / base, base, b);
	write(1, &b[nbr % base], 1);
}

int			ft_printf(const char *format, ...)
{
	va_list ar;

	char	*str;	
	char	*s;
	long	nbr;

	int		minus;
	int		len;
	int		width;
	int		dot;
	int		zero;
	int		space;

	int		dlina = 0;

	va_start(ar, format);
	str = (char *)format;

	while (*str)
	{
		if (*str == '%')
		{
			printf("in\n");
			str++;
			width = 0;
			minus = 0;
			dot = -1;
			len = 0;
			zero = 0;
			space = 0;

			while (*str >= '0' && *str <= '9')
			{	
				width = width * 10 + (*str - '0');
				str++;
			}
			printf("width = %d \n", width);
			if (*str == '.')
			{
				dot = 0;
				str++;
				while (*str >= '0' && *str <= '9')
				{
					dot = dot * 10 + (*str - '0');
					str++;
				}
			} 
			printf("dot = %d \n", dot);
			if (*str == 's')
			{
				s = va_arg(ar, char*);
				if (!s)
					s = "(null)";
				while (s[len])
					len++;
			}
			if (*str == 'd')
			{
				nbr = va_arg(ar, int);
				if (nbr < 0)
				{
					minus = 1;
					nbr = -nbr;
				}
				len = nbrlen(nbr, 10) + minus;
			}
			printf("minus = %d \n", minus);
			printf("len = %d \n", len);
			if (*str == 'x')
			{
				nbr = va_arg(ar, unsigned);
				len = nbrlen(nbr, 16);
			}
			if (dot >= len && *str != 's')
				zero = dot - len + minus;
			else if (dot < len && dot > -1 && *str == 's')
				len = dot;
			else if (dot == 0 && (*str == 's' || nbr == 0))
				len = 0;
			printf("len = %d , width = %d, zero = %d, space = %d\n", len, width, zero, space);
			space = width - zero - minus;
			while (space-- > 0)
				dlina += write(1, " ", 1);
			if (minus == 1)
				write(1, "-", 1);
			while (zero-- > 0)
				dlina += write(1, "0", 1);
			if (*str = 's')
				write(1, s, len);
			else if (*str = 'd' && len > 0)
				ft_putnbr(nbr, 10, "0123456789");
			
			else if (*str = 'x' && len > 0)
				ft_putnbr(nbr, 16, "0123456789abcdef");
			dlina += len;
		}
		else
			dlina += write(1, str, 1);
		str++;
	}
	va_end(ar);
	return (dlina);
}




int		main()
{
	ft_putnbr(32, 10, "0123456789");
	int b = ft_printf("hellom world %125.5d\n", -32);
	int c = printf("hellom world %125.5d\n", -32);
	printf("%d\n", b);
	printf("%d\n", c);
	return (0);
}
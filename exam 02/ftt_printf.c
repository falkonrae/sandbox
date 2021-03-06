#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_numlen(int num, int base)
{
	int i = 1;
	while (num /= base)
		i++;
	return (i);
}

void ft_putnbr(int num, int base, char *s)
{
	if (num >= base)
		ft_putnbr(num / base, base, s);
	write(1, &s[num % base], 1);
}

int			ft_printf(const char *format, ...)
{
	va_list ar;

	char *str, *buf_str;
	int minus, len, width, dot, zero, space;
	int num, dlina = 0;
	va_start(ar, format);
	str = (char*)format;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			width = 0;
			dot = -1;
			minus = 0;
			len = 0;
			zero = 0;
			space = 0;

			

			while (*str >= '0' && *str <= '9')
			{
				width = width * 10 + (*str - '0');
				str++;
			}
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
			if (*str = 's')
			{
				buf_str = va_arg(ar, char *);
				if (!buf_str)
					buf_str = "(null)";
				while (buf_str[len])
					len++;
			}
			if (*str == 'd')
			{
				num = va_arg(ar, int);
				if (num < 0)
				{
					num = -num;
					minus = 1;
				}
				len = ft_numlen(num, 10) + minus;
			}
			if (*str == 'x')
			{
				num = va_arg(ar, unsigned int);
				len = ft_numlen(num, 16);
			}
			if (dot >= len && *str != 's')
				zero = dot - len + minus;
			else if (dot > -1 && dot < len && *str == 's')
				len = dot;
				else if (dot ==0 && (*str == 's' || num == 0))
					len = 0;
			space = width - zero - len;
			while (space > 0)
			{
				dlina += write(1, " ", 1);
				space--;
			}
			if (minus)
				write (1,"-", 1);
			while (zero)
			{
				dlina = write(1, "0", 1);
				zero--;
			}
			if (*str == 's')
				write(1, buf_str, len);
			else if (len > 0 && *str == 'd')
				ft_putnbr(num, 10, "0123456789");
			else if (len > 0 && *str == 'x')
				ft_putnbr(num, 16, "0123456789abcdef");
			dlina += len;
		}
		else 
			dlina += write(1, str, 1);
		str++;
	}
	va_end(ar);
	return (dlina);
}

int main()
{
	int b = ft_printf("hellom world %125.5d\n", -32);
	int c = printf("hellom world %125.5d\n", -32);
	printf("%d\n", b);
	printf("%d\n", c);
	return (0);

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 14:47:38 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"




int		proc_type(t_list *flags, va_list ap)
{
	int len;

	len = 1;
	if (flags->type == 'c')
		len += proc_char(flags, va_arg(ap, int));
	if (flags->type == 's')
		len += proc_string(flags, va_arg(ap, char *));
	if (flags->type == 'p')
		len += proc_pointer(flags, va_arg(ap, unsigned long int));
	// if (flags->type == 'd' || flags->type == 'i')
	//     len += proc_int(flags, va_arg(ap, int));
	// if (flags->type == 'u')
	// 	len += proc_uint(flags, va_arg(ap, unsigned int));
	// if (flags->type == 'x')
	// 	len += proc_hex(flags, va_arg(ap, unsigned int), 0);
	// if (flags->type == 'X')
	// 	len += proc_hex(flags, va_arg(ap, unsigned int), 1);
	// if (flags->type == '%')
	// 	len += proc_percent(flags);
	return (len);
}

int		parse_flags(const char *s, int i, t_list *flags, va_list ap)
{
	while (s[i] && (ft_isdigit(s[i]) || ft_istype(s[i]) || ft_isflag(s[i])))
	{
		i++;
		if (s[i] == '0' && !flags->minus && !flags->width && !flags->dot)
			flags->zero = 1;
		if (s[i] == '.')
			i = flag_dot(s, i, flags, ap);
		if (s[i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		if (s[i] == '*')
			flag_width(flags, ap);
		if (ft_isdigit(s[i]))
			flag_digit(flags, s[i]);
		if (ft_istype(s[i]))
			flags->type = s[i];
	}
	return (i);
}


void	init_list(t_list *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = -1;
	flags->star = 0;
}

int		ft_parse_input(const char *s, va_list ap)
{
	t_list	flags;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (1)
	{
		init_list(&flags);
		if (!s[i])
			return (len);
		if (s[i] == '%')
		{
			// check_space(s, &i, &len); для бонусов
			i = parse_flags(s, i, &flags, ap);
		}
		if (flags.type)
			len += proc_type(&flags, ap);
		if (s[i] != '%' || !flags.type)
		{
			ft_putchar(s[i]);
			len++;
		}
			
		i++;
	}
}

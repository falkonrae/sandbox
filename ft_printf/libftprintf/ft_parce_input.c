/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/23 13:47:11 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	flag_dot(const char *s, int i, t_list flags, va_list ap)
{
	i++;
	if (s[i] == '*')
		flags->dot = va_arg(ap, int);
	if (s[i] != '*')
	{
		while (ft_isdigit(s[i]))
		{
			flags->dot = flags->dot * 10 + s[i] - '0';
			i++;
		}
	}
	return (i);

}

int		parse_flags(const char *s, int *i, t_list *flags, va_list ap)
{
	*i += 1;
	while (s[*i] && (ft_isdigit(s[*i]) || ft_istype(s[*i]) || ft_isflag(s[*i])))
	{
		if (s[*i] == '0' && !flags->minus && flags->width)
			flags->zero = 1;
		if (s[*i] == '.')
			i = flag_dot(s, *i, flags, ap);
		if (s[*i] == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		if (s[*i] == '*')
		if (ft_isdigit(s[*i]))
		if (ft_istype(s[*i]))
			flags->type = s[*i];
	}

	return (*i);
}


void	init_flags(t_list *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
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
		init_flags(&flags);
		if (!s[i])
			return (len);
		if (s[i] == '%')
		{
			// check_space(s, &i, &len); для бонусов
			i = parse_flags(s, &i, &flags, ap);
		}
		if (s[i] != '%' || !flags.type)
		{
			ft_putchar(s[i]);
			len++;
		}
		if (flags.type)
		//len = process_types(//)
		i++;
	}
}

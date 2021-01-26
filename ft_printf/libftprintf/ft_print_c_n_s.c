/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_n_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 10:27:43 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int		ft_print_spaces(int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar(' ');
		i++;
	}
	return (count);
}

int		ft_print_str(char *s, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int		proc_string(t_list *flags, char *s)
{
	int len;
	int kol;

	if (!s)
		s = NULL;
	len = 0;
	kol = ft_strlen(s);
	if (flags->dot >= 0 && flags->dot < kol)
	{
		kol = flags->dot;
		len += kol;
	}
	if (flags->width >= 0 && !flags->minus)
	{
		len += ft_print_spaces(flags->width - kol);
	}
	if (!flags->minus) 
		len += ft_print_str(s, kol);
	
	if (flags->minus)
	{
		len += ft_print_str(s, kol);
		len += ft_print_spaces(flags->width - kol);
	}
	return (len - 1);
}


int		proc_char(t_list *flags, char c)
{
	int len;

	len = 0;
	if (flags->minus)
		ft_putchar(c);
	len += ft_print_spaces(flags->width);
	if (!flags->minus)
		ft_putchar(c);
	return (len);
}
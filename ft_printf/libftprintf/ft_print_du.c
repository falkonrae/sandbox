/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_du.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/30 10:45:13 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// int	process_int_positive(t_list *flags, int kol, int dot, char *s)
// {
// 	if (flags->minus)
// 		return (ft_space_zero(dot, 1) + ft_putstr(s) +
// 				ft_space_zero(flags->width - dot - kol, 0));
// 	else if (flags->zero && flags->dot == -1)
// 		return (ft_space_zero(flags->width - kol, 1) + ft_putstr(s));
// 	else
// 		return (ft_space_zero(flags->width - dot - kol, 0) +
// 				ft_space_zero(dot, 1) + ft_putstr(s));
// }

// int	process_int_negative(t_list *flags, int kol, int dot, char *s)
// {
// 	if (flags->minus)
// 		return (ft_putchar('-') + ft_space_zero(dot, 1) +
// 				ft_putstr(s + 1) +
// 				ft_space_zero(flags->width - dot - kol, 0));
// 	else if (flags->zero && flags->dot == -1)
// 		return (ft_putchar('-') + ft_space_zero(flags->width - kol, 1)
// 				+ ft_putstr(s + 1));
// 	else
// 		return (ft_space_zero(flags->width - dot - kol, 0) +
// 				ft_putchar('-') + ft_space_zero(dot, 1) +
// 				ft_putstr(s + 1));
// }

// int	proc_int(t_list *flags, int i)
// {
// 	int		length;
// 	int		kol;
// 	int		dot;
// 	char	*s;


// 	if (i == 0 && flags->dot == 0)
// 		return (ft_space_zero(flags->width, 0));
		
// 	if(!(s = ft_itoa(i)))
// 		return (0);
// 	kol = ft_strlen(s);
// 	printf("flags->dot - kol = %d\n", flags->dot - kol);
// 	printf("i= %d\n", i);
// 	printf("flags->dot = %d\n", flags->dot);
// 	printf("dotbef = %d\n", dot);
// 	if (i >= 0)
// 		dot = flags->dot - kol > 0 ? flags->dot - kol : 0;
// 	else
// 		dot = flags->dot - kol + 1 > 0 ? (flags->dot - kol + 1) : 0;
// 	printf("flags->dot = %d\n", flags->dot);
// 	printf("dot = %d\n", dot);
// 	length = i >= 0 ? process_int_positive(flags, kol, dot, s)
// 					: process_int_negative(flags, kol, dot, s);
// 	free(s);
// 	return (length);
// }

int	proc_int(t_list *flags, int i)
{
	int		len;
	int		kol;
	int		dot;
	char	*s;
	int 	minus;

	minus = 0;
	len = 0;
	if (i == 0 && flags->dot == 0)
		return (ft_space_zero(flags->width, 0));
	if(!(s = ft_itoa(i)))
		return (0);
	kol = ft_strlen(s);
	printf("kol= %d\n", kol);
	 printf("flags->dot - kol = %d\n", flags->dot - kol);
	// printf("i= %d\n", i);
	 printf("flags->dot = %d\n", flags->dot);
	// printf("dotbef = %d\n", dot);
	// printf("len = %d\n",len);
	// if (flags->dot >= 0 && flags->dot < kol)
	// 	kol = flags->dot;
	if (i < 0)
	{	len += ft_putchar('-');
	minus = 1;}
		// printf("len1 = %d\n",len);
	// if (flags->minus)
	// 	len += 
	// 			ft_putstr(s + 1) +
	// 			ft_space_zero(flags->width - dot - kol, 0);
	// if (flags->zero)
	// 	len += ft_space_zero(flags->width - kol - minus, 1);
	// if (flags->dot && flags->width)
	// 	kol = flags->dot;
	if (flags->dot > 0)
		len += ft_space_zero(flags->dot - kol + minus, 1);
	// printf("len2 = %d\n",len);
	if (flags->zero && flags->width)
		len += ft_space_zero(flags->width - kol, 1);
	else if (!flags->minus && flags->width)
		len += ft_space_zero(flags->width - kol, 0);
	len += ft_putstr(s + 1);
	//printf("kol= %d\n", kol);
	if (flags->minus)
		len += ft_space_zero(flags->width - kol, 0);		//+ ft_putstr(s + 1);
	// else
	// 	len += ft_space_zero(flags->width - dot - kol, 0) +
	// 			ft_putchar('-') + ft_space_zero(dot, 1) +
	// 			ft_putstr(s + 1);
	free(s);
	return (len);
}

// int	ft_print_zeros(int kol)
// {
// 	int i;

// 	if (kol <= 0)
// 		return (0);
// 	i = 0;
// 	while (i < kol)
// 	{
// 		ft_putchar('0');
// 		i++;
// 	}
// 	return (kol);
// }

// int	process_uint2(t_list *flags, int kol, int dot, char *s)
// {
// 	if (flags->minus)
// 		return (ft_print_zeros(dot) + ft_putstr(s) +
// 				ft_print_space(flags->width - dot - kol));
// 	else if (flags->zero && flags->dot == -1)
// 		return (ft_print_zeros(flags->width - kol) + ft_putstr(s));
// 	else
// 		return (ft_print_space(flags->width - dot - kol) +
// 				ft_print_zeros(dot) + ft_putstr(s));
// }

// int	process_uint(t_list *flags, unsigned int u)
// {
// 	int		length;
// 	int		kol;
// 	int		dot;
// 	char	*s;

// 	if (u == 0 && flags->dot == 0)
// 		return (ft_print_space(flags->width));
// 	s = ft_utoa(u);
// 	if (!s)
// 		return (0);
// 	kol = ft_strlen(s);
// 	dot = flags->dot - kol > 0 ? flags->dot - kol : 0;
// 	length = process_uint2(flags, kol, dot, s);
// 	free(s);
// 	return (length);
// }

int	proc_uint(t_list *flags, unsigned int u)
{
	int		len;
	int		kol;
	int		dot;
	char	*s;

	len = 0;
	if (u == 0 && flags->dot == 0)
		return (ft_space_zero(flags->width, 0));
	if(!(s = ft_utoa(u)))
		return (0);
	kol = ft_strlen(s);
	// printf("kol= %d\n", kol);
	//  printf("flags->dot - kol = %d\n", flags->dot - kol);
	// printf("i= %d\n", i);
	 //printf("flags->dot = %d\n", flags->dot);
	// printf("dotbef = %d\n", dot);
	// printf("len = %d\n",len);
	// if (flags->dot >= 0 && flags->dot < kol)
	// 	kol = flags->dot;
	// if (u < 0)
	// {	len += ft_putchar('-');
	// minus = 1;}
		// printf("len1 = %d\n",len);
	// if (flags->minus)
	// 	len += 
	// 			ft_putstr(s + 1) +
	// 			ft_space_zero(flags->width - dot - kol, 0);
	// if (flags->zero)
	// 	len += ft_space_zero(flags->width - kol - minus, 1);
	// if (flags->dot && flags->width)
	// 	kol = flags->dot;
	if (flags->dot > 0)
		len += ft_space_zero(flags->dot - kol, 1);
	// printf("len2 = %d\n",len);
	if (flags->zero && flags->width)
		len += ft_space_zero(flags->width - kol, 1);
	else if (!flags->minus && flags->width)
		len += ft_space_zero(flags->width - kol, 0);
	len += ft_putstr(s);
	//printf("kol= %d\n", kol);
	if (flags->minus)
		len += ft_space_zero(flags->width - kol, 0);		//+ ft_putstr(s + 1);
	// else
	// 	len += ft_space_zero(flags->width - dot - kol, 0) +
	// 			ft_putchar('-') + ft_space_zero(dot, 1) +
	// 			ft_putstr(s + 1);
	free(s);
	return (len);
}
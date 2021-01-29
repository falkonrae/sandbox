/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtahm <wtahm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:53:01 by wtahm             #+#    #+#             */
/*   Updated: 2021/01/26 11:05:47 by wtahm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *f, ...)
{
	int		length;
	va_list	args;

	va_start(args, f);
	length = process_input(f, args);
	va_end(args);
	return (length);
}

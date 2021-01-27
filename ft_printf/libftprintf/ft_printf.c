/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:03:17 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/27 12:57:55 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int 	ft_printf(const char *s, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, s);
	len = ft_parse_input(s, ap);
	va_end(ap);
	return (len);
}



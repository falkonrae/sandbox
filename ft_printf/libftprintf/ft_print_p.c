/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacob <vjacob@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 19:58:04 by vjacob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int i_count(unsigned long i)
{
	//
	//printf("ud long = %ld\n", i);
	int count;
	if (!i)
		return (1);
	count = 0;
	while (i)
	{
		i /= 16;
		count++;
	}
	//printf("count = %d\n", count);
	return (count);	
}

int		ft_print_str_p(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (i);
}

int		ft_to_hex_string(unsigned long p, char **s)
{
    int		count;
    int		i;
    char	h;
	
    count = i_count(p);
       if (!(*s = malloc((count + 1) * sizeof(char))))
        return (-1);
    (*s)[count] = '\0';
    i = count - 1;
    while (i >= 0)
    {
        h = p % 16;
        if (h < 10)
            (*s)[i] = h + 48;
        else
            (*s)[i] = h + 87;
        p /= 16;
        i--;
    }
    return (count);
}
// int 	proc_hex(t_list *flags, unsigned long i)
// {
// 	int count;
// 	char *str;
	
// 	count = i_count(i);
// 	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
// 	return (0);
// 	if (i)
// 	{
// 		while (i)
// 		{
// 			i = i / 16 + count;
// 			str[ft_strlen(str)] = '\0';
// 			count--;
// 			if (i / 16 < 10)
// 				str[count] = i % 16 + 48;
// 			else
// 				str[count] = i % 16 + 87;
// 			i /= 16;
// 			count--;
			
// 		}
// 	}
// }

int    proc_pointer(t_list *flags, unsigned long i)
{
    int len;
    char *str;
    int count;

  len = 0;
  count = ft_to_hex_string(i, &str);
 // printf("i = %d\n", count);
	if (flags->minus)
	{
		len += ft_print_str_p("0x") + ft_print_str_p(str) + ft_print_spaces(flags->width - count - 2);
	}
	// if (flags->dot && flags->width)
	// { 
	// 	len += ft_print_str_p("0x") + ft_print_spaces(flags->width); 
	// }
	else if (flags->zero)
         len += ft_print_str_p("0x") + ft_print_zero(flags->width - count - 2) 
		 	+ ft_print_str_p(str);
	else //(flags->width >= 0 && !flags->minus)
	{
		len += ft_print_spaces(flags->width - count - 2) + ft_print_str_p("0x") + ft_print_str_p(str);
		
	}
	// if (!flags->minus) 
	// 	len += ft_print_str("0x", 2);
	
			// len += ft_print_str_p("0x");
			// len += flags->dot;
        //put string "0x" with added precision flag +length
		//add width with zeros + length 
			
		// }
		// str = "\0";
  //  }
// 	
//     count = 0;
//   	len += ft_print_str_p("0x");
// 	  //if (flags->dot >= 0)
    return (len - 1);
}



// int     ft_to_capital_hex_string(unsigned long p, char **s)
// {
//     int     count;
//     int     i;
//     char    h;
//     count = i_count(p);
//     *s = malloc((count + 1) * sizeof(char));
//     if (!*s)
//         return (-1);
//     (*s)[count] = '\0';
//     i = count - 1;
//     while (i >= 0)
//     {
//         h = p % 16;
//         if (h < 10)
//             (*s)[i] = h + 48;
//         else
//             (*s)[i] = h + 55;
//         p /= 16;
//         i--;
//     }
//     return (count);
// }
// int     process_pointer(t_flags *fs, unsigned long p)
// {
//     int     length;
//     int     count;
//     char    *s;
//     length = 0;
//     count = ft_to_hex_string(p, &s);
//     if (count == -1)
//         return (0);
//     if (fs->minus)
//         length += ft_putstr("0x") + ft_putstr(s) +
//                     ft_print_spaces(fs->width - count - 2);
//     else if (fs->zero)
//         length += ft_putstr_fd("0x", 1) +
//                     ft_print_zeros(fs->width - count - 2) + ft_putstr_fd(s, 1);
//     else
//         length += ft_print_spaces(fs->width - count - 2) +
//                     ft_putstr_fd("0x", 1) + ft_putstr_fd(s, 1);
//     free(s);
//     return (length);
// }
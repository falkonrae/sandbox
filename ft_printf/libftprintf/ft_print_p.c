/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falkonrae <falkonrae@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:13:44 by vjacob            #+#    #+#             */
/*   Updated: 2021/01/26 11:18:34 by falkonrae        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

int    proc_pointer(t_list *flags, unsigned long i)
{
    int len;
    char *str;
    int count;

  len = 0;
  len += ft_print_str_p("0x");
   if (!i)
    {
		if (flags->dot == 0)
		{
			len += ft_print_str_p("0x");
        //put string "0x" with added precision flag +length
		//add width with zeroc + length 
		}
		str = "\0";
    }
	if (i)
	{
		while (i)
		{
			i = i / 16 + count;
			if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
				return (0);
			str[ft_strlen(str)] = '\0';
			count--;
			if (i / 16 < 10)
				str[count] = i % 16 + 48;
			else
				str[count] = i % 16 + 87;
			i /= 16;
			count--;
			
		}
	}
    count = 0;
  	len += ft_print_str_p("0x");
	  //if (flags->dot >= 0)
    return (len);
}

// char	*ft_strjoin(char *s1, char *s2, int f)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	i = -1;
// 	j = -1;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
// 		return (NULL);
// 	while (s1[++i] != '\0')
// 		str[i] = s1[i];
// 	while (s2[++j] != '\0')
// 		str[i + j] = s2[j];
// 	str[i + j] = '\0';
// 	if ((f == 1 || f == 3) && s1)
// 		free((char*)s1);
// 	if ((f == 2 || f == 3) && s2)
// 		free((char*)s2);
// 	return (str);
// }

// char			*proc_pointer(long long int n, char *base)
// {
// 	char		*str;

// 	if (!(str = (char *)ft_calloc(sizeof(char), 2)))
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		str[0] = '-';
// 		str[1] = '\0';
// 		str = ft_strjoin(str, proc_pointer(-n, base), 3);
// 	}
// 	else if (n >= (long long int)ft_strlen(base))
// 	{
// 		free(str);
// 		str = ft_strjoin(proc_pointer(n / ft_strlen(base), base),
// 			proc_pointer(n % ft_strlen(base), base), 3);
// 	}
// 	else if (n < (long long int)ft_strlen(base) && n >= 0)
// 	{
// 		str[0] = base[n];
// 		str[1] = '\0';
// 	}
// 	return (str);
// }

// int		n_size(int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 		len++;
// 	while (n)
// 	{
// 		n = n / 10;
// 		len++;
// 	}
// 	return (len);
// }

// char	*new_str(char *str, int nlen, int neg, int n)
// {
// 	while (nlen >= 0)
// 	{
// 		if (nlen == 0 && neg == 1)
// 		{
// 			str[0] = '-';
// 			nlen--;
// 		}
// 		else
// 		{
// 			str[nlen] = (n % 10) + '0';
// 			nlen--;
// 			n = n / 10;
// 		}
// 	}
// 	return (str);
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	int		nlen;
// 	int		neg;

// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));
// 	neg = 0;
// 	nlen = n_size(n);
// 	str = (char *)malloc(sizeof(char) * (nlen + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	if (n < 0)
// 	{
// 		neg = 1;
// 		n = -n;
// 	}
// 	str[nlen] = '\0';
// 	nlen--;
// 	return (new_str(str, nlen, neg, n));
// }

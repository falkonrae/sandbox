/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_prsg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:24:49 by frfrance          #+#    #+#             */
/*   Updated: 2020/12/31 01:15:44 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

int				env_size(char **list)
{
	int i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

// int				error_file(char *str)
// {
// 	while (*str && *str != ' ')
// 		str++;
// 	while (*str && *str == ' ')
// 		str++;

// 	if (!ft_strncmp("<<", str, 3))
// 		ft_printf("minishell: %s `<<'\n", SYNTAX_ERR);
// 	else if (!ft_strncmp(">>", str, 2))
// 		ft_printf("minishell: %s `>>'\n", SYNTAX_ERR);
// 	else if (!ft_strncmp("<", str, 2))
// 		ft_printf("minishell: %s `<'\n", SYNTAX_ERR);
// 	else if (!ft_strncmp(">", str, 1))
// 		ft_printf("minishell: %s `>'\n", SYNTAX_ERR);
// 	else if (!ft_strncmp("<<<", str, 3))
// 		ft_printf("minishell: %s `<<<'\n", SYNTAX_ERR);
// 	else
// 		ft_printf("minishell: %s `newline'\n", SYNTAX_ERR);
// 	g_error = 1;
// 	return (-1);
// }

int				parse_v1(char *str, int option)
{
	int			i;
	int			n_semicolon;
	int 		quote;

	i = 0;
	n_semicolon = 0;
	quote = 0;
	while (str[++i])
	{
		if (str[i] == '"' && str[i - 1] != '\\')
			quote++;
		if (str[i] == ';' && (quote % 2) == 0 && str[i - 1] != '\\')
		{
			if (option == 1)
				return (i);
			n_semicolon++;
		}
	}
	if (option == 1)
		return (-1);
	return (n_semicolon);
}

char			**parse_v2(char *str)
{
	char		**tab;
	int			i;
	int			last_i;

	last_i = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (parse_v1(str, 0) + 2))))
		return (NULL);
	while (parse_v1(str + last_i, 1) != -1)
	{
		tab[i] = ft_substr(str + last_i, 0, parse_v1(str + last_i, 1));
		last_i += ft_strlen(tab[i]) + 1;
		i++;
	}
	tab[i] = ft_substr(str + last_i, 0, ft_strlen(str + last_i));
	tab[i + 1] = NULL;
	return (tab);
}

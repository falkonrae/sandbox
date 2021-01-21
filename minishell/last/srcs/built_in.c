/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:14:13 by rqouchic          #+#    #+#             */
/*   Updated: 2021/01/14 15:43:10 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

int         echo_test_option(char *str)
{
	int i;

	if (str)
	{
		if (str[0] != '-')
			return (0);
		i = 1;
		while (str[i] == 'n')
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int			ft_cmd_echo(char **str, char **env)
{
	int		i;
	int		j;
	int		flag;

	i = 1;
	flag = 0;
	while (echo_test_option(str[i]))
	{
		i++;
		flag = 1;
	}
	j = i;
	while (str[i])
	{
		if (i > j)
			ft_putchar(' ');
		if (ft_strcmp(str[i], "~") == 0)
			ft_putstr(get_env(env, "HOME"));
		else
			ft_putstr(str[i]);
		i++;
	}
	if (!flag)
		ft_putchar('\n');
	return (0);
}

int			ft_pwd(char **env)
{
	char	*s;

	return_valu = 0;
	s = getcwd(NULL, 0);
	if (s == NULL)
		ft_printf("%s\n", get_env(env, "PWD"));
	else
	{
		ft_printf("%s\n", s);
		free(s);
	}
	return (return_valu);
}

int			check_error(char **str, int count)
{
	int		error;
	int		i;
	int		j;

	error = 0;
	i = 0;
	j = 1;
	if (count != 1)
	{
		if (str[j][i] == '-' || str[j][i] == '+')
			i++;
		while (str[j][i])
		{
			if (str[j][i] < '0' || str[j][i] > '9')
				break ;
			i++;
		}
		if (str[j][i] || (i == 1 && (str[j][i - 1] == '-'
			|| str[j][i - 1] == '+')))
			error = 255;
		else
			return_valu = ft_atoi(str[1]);
	}
	return (error);
}

int			check_numeric(char **str)
{
	int arg_count;
	int	num_error;

	arg_count = 0;
	num_error = 0;
	while (str[arg_count])
		arg_count++;
	num_error = check_error(str, arg_count);
	if (num_error)
	{
		return_valu = 255;
		printf("exit\nminishell: exit: %s mumeric argument required\n", str[1]);
		exit(return_valu);
	}
	if (arg_count > 2)
	{
		return_valu = 1;
		ft_printf("exit\nminishell: exit: Too many arguments\n");
		return (return_valu);
	}
	return (0);
}

/*
** ft_exit fonction doit etre free
*/

int			ft_exit(char **str, char **env)
{
	int arg_error;

	(void)**env;
	arg_error = check_numeric(str);
	if (arg_error == 0)
	{
		ft_printf("exit\n");
		sleep (5);
		exit(return_valu);
	}
	return (return_valu);
}

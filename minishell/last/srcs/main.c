/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 15:07:21 by rqouchic          #+#    #+#             */
/*   Updated: 2021/01/14 14:21:09 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

void	ft_close_pipes(int **pipes, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
	}
}

int		ft_nb_pipe(char *str, int o)
{
	int	j;
	int	nb_pipe;
	int	quote;

	j = -1;
	nb_pipe = 0;
	quote = 0;
	while (str[++j])
	{
		if (str[j] == '"' && str[j - 1] != '\\')
			quote++;
		if (str[j] == '|' && (quote % 2) == 0 && str[j - 1] != '\\')
		{
			if (o == 1)
				return (j);
			nb_pipe++;
		}
	}
	if (o == 1)
		return (-1);
	return (nb_pipe);
}

int		ft_prsg_pipe(char *str, t_strt *strt)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (ft_nb_pipe(str + j, 1) != -1)
	{
		strt[i].str = ft_substr(str + j, 0,
			ft_nb_pipe(str + j, 1));
		j += ft_strlen(strt[i].str) + 1;
		i++;
	}
	strt[i].str = ft_substr(str + j, 0, ft_strlen(str + j));
	strt[i + 1].str = NULL;
	if (arg_pipe(strt) == -1)
		return (-1);
	return (0);
}

int		*splitsaisie(t_shell *data)
{
	char	**arg_p;
	int		i;

	arg_p = NULL;
	i = -1;
	recupere_le_path(data);

	parse_dollar(&data->buffer, data->copyenv);


	if (data->buffer[0] == '\0' || data->buffer[0] == ' ')
		return (0);
	arg_p = parse_v2(data->buffer);


	while (arg_p[++i])
		ft_exec_pipe(arg_p[i], data);


	free_array(arg_p);
	// free(data->buffer);
	free_array(data->path_split);

	return (0);
}



int		prompt(t_shell *data)
{
	g_file = 1;

	while (1)
	{

		if (!get_next_line(0, &data->buffer))
		{
			if (ctrl_d())
				break ;
		}
		if (data->buffer[0] == '\0' || data->buffer[0] == ' ')
		{
			write(1, "MINISHELL $> ", 13);
		}
		else
		{
			splitsaisie(data);
			write(1, "MINISHELL $> ", 13);

		}
		free(data->buffer);
	}
	free(g_last);
	free(data->buffer);
	free_array(data->copyenv);
	// free(data->env_path);
	// free(data);
	return (0);
}

int		main(int ac, char **av, char **env)
{
	t_shell	data;

	(void)ac;
	(void)av;
	printf("\n\t\t\t\t//////////// WELCOME TO MY MINISHELL ////////////\n");
	write(1, "MINISHELL $> ", 13);
	ft_copy_tab2d(&data, env);

	main_signal();
	prompt(&data);



	return (0);
}

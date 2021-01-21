/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:53:45 by frfrance          #+#    #+#             */
/*   Updated: 2020/12/24 14:51:57 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

void			fd_center(t_strt *strt)
{
	if (strt->input_s != 0)
	{
		dup2(strt->input_s, 0);
		close(strt->input_s);
	}
	if (strt->output_s != 1)
	{
		dup2(strt->output_s, 1);
		close(strt->output_s);
	}
}

int				pipe_craft(t_strt *strt, int **pipes)
{
	int			j;
	int			size;

	j = 0;
	while (strt[j].str)
		j++;
	size = --j;
	if (size == 0)
		return (0);
	j = 0;
	while (j < size)
	{
		if (pipe(pipes[j]) == -1)
			ft_print_exit("Error: pipe\n");
		j++;
	}
	return (size);
}

void			ft_co_pipe(t_strt *strt, int nb_pipe, int **pipes)
{
	int			i;

	i = -1;
	while (strt[++i].str)
	{
		if (strt[i].input_s != 0)
			;
		else if (strt[i].input_s == 0 && i != 0)
			strt[i].input_s = pipes[i - 1][0];
		if (strt[i].output_s != 1)
			;
		else if (strt[i].output_s == 1 && i < nb_pipe && pipes[i][0])
			strt[i].output_s = pipes[i][1];
	}
}

void			ft_pipe_center(t_strt *strt, int **pipes, char *str,
								t_shell *data)
{
	int			i;
	int			nb_pipe;

	i = -1;
	// creation de pipe par rapport a lindex
	nb_pipe = pipe_craft(strt, pipes);
	// connecte les pipes avec les fd
	while (strt[++i].str)
		ft_co_pipe(strt, nb_pipe, pipes);
	i = -1;


	// parcour mes chaine (chaine 1 ls) | (chaine 2 pwd) | (chaine 3 echo)
	while (strt[++i].str)
		pipe_pid[i] = ft_pipes_exec(&strt[i], pipes, ft_nb_pipe(str, 0), data);
	ft_close_pipes(pipes, ft_nb_pipe(str, 0));
	wait_pids(pipe_pid, ft_nb_pipe(str, 0) + 1, strt);
}

int				ft_exec_pipe(char *str, t_shell *data)
{
	t_strt		*strt;
	int			i;
	int			nb_pipe;
	int			**pipes;

	if (!(strt = init_array(str)))
		return (-1);
	pipes = NULL;
	nb_pipe = ft_nb_pipe(str, 0);

	if (!(init_pipe(nb_pipe, &pipes)))
		return (free_clean_input(strt, pipes, nb_pipe));
	pipe_pid[ft_nb_pipe(str, 0) + 1] = 0;
	if (ft_prsg_pipe(str, strt) == -1)
		return (free_clean_input(strt, pipes, nb_pipe));

	i = -1;
	while (strt[++i].str)
		ft_redirec_for_pipe(&strt[i]);

	if (i > 1)
		ft_pipe_center(strt, pipes, str, data);
	else
		no_pipe_exec(&strt[0], data);
	return (free_clean_input(strt, pipes, nb_pipe));
}

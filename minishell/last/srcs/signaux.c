/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:45:42 by frfrance          #+#    #+#             */
/*   Updated: 2020/12/25 03:10:18 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

void			ctrl_c(int sig)
{
	int i;

	(void)sig;
	if (!pipe_pid)
	{
		write(1, "\nMINISHELL $> ", 14);
		return_valu = 130;
	}
	else
	{
		i = -1;
		while (++i)
			kill(pipe_pid[i], sig);
		write(1, "\n", 1);
		return_valu = 130;
	}
}

int				ctrl_d(void)
{
	printf("g_file %d\n", g_file);
	if (!g_file)
		ft_printf("exit\n");
	return (1);
}

int				main_signal(void)
{

	if (signal(SIGQUIT, &ctrl_quit) == SIG_ERR)
	{
		ft_printf("Could not set signal handler\n");
		return (1);
	}
	if (signal(SIGINT, &ctrl_c) == SIG_ERR)
	{
		ft_printf("Could not set signal handler\n");
		return (1);
	}
	return (0);
}


void			ctrl_quit(int sig)
{
	int i;

	i = -1;
	(void)sig;


	if (pipe_pid)
	{
		ft_printf("Quit\n");
		while (++i)
			kill(pipe_pid[i], 2);
		return_valu = 131;

	}
	else
	{
		write(1, "\b\b  \b\b", 6);
		return_valu = 127;
	}
}

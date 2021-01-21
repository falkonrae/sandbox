/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:02:05 by frfrance          #+#    #+#             */
/*   Updated: 2020/12/02 20:53:36 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

int				is_built_in(char *cmd)
{
	const char	*built_in[] = {"pwd", "cd", "env", "export",
								"echo", "exit", "unset", NULL};
	int			i;
	int			error;

	i = 0;
	error = 1;
	while (built_in[i])
	{
		if (!strcmp(built_in[i], cmd))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

pid_t			exit_exec1(char ***func, char ***env_var, pid_t pid)
{
	clean_array(*func);
	free(*env_var);
	return (pid);
}

void			fonction_cat_for_pipe(t_shell *data, char **func, int i)
{
	data->temp = ft_strdup(func[0]);

	// printf("data %s\n", data->temp);
	// printf("func[0] %s\n", func[0]);

	free(func[0]);
	strcat(data->bin, data->path_split[i]);

	strcat(data->bin, "/");

	strcat(data->bin, data->temp);
	
	// free(func[0]);
	func[0] = ft_strdup(data->bin);

	
	
	
	
	
	
	
}



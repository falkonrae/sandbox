/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:32:30 by frfrance          #+#    #+#             */
/*   Updated: 2021/01/05 11:47:54 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

void	free_chaine_three(char *str_1, char *str_2, char *str_3)
{
	free(str_1);
	free(str_2);
	free(str_3);
}



char	*pwd_for_exec_bin(void)
{
	char		buff[1024];
	char		*pwd;

	ft_memset(&buff, 0, 1024);
	pwd = getcwd(buff, 1024);
	if (!pwd)
		ft_printf("%s\n", strerror(errno));
	return (pwd);
}

void	fonction_cat(t_shell *data, char **func, int i)
{
	data->temp = ft_strdup(func[0]);
	strcat(data->bin, data->path_split[i]);
	strcat(data->bin, "/");
	strcat(data->bin, func_for_var);
	func[0] = ft_strdup(data->bin);
}

void	bin_center(t_shell *data, char **func)
{
	// ../test/a.out
	if (func[0][0] == '.' && func[0][1] == '.')
	{
		printf("exec ..\n");

		execve(func[0], func, data->copyenv);
		error_bin = 1;

	}

	// ~/42/minishell/test/a.out
	else if (func[0][0] == '~')
	{
		int j = 0;
		printf("exec vague\n");
		exec_vague(func, data, j);
		error_bin = 1;
	}

	// ls
	else if (func[0][0] != '/'  && func[0][0] != '~' && ft_strncmp(func[0], "./", 2) != 0)
	{
		printf("exec bin\n");
		exec_bin(func, data);
		
	}


	// a.out
	else if (func[0][0] == '.')
	{
		printf("exec point\n");
		exec_point(func, data);
		error_bin = 1;

	}


	else if (func[0][0] == '/')
	{
		printf("exec slash\n");
		execve(func[0], func, data->copyenv);
		error_bin = 1;

	}
	
	path_error(func);
	
	
	// /bin/ls
	// /Users/Kazuuma/42/germain/a.out
	// else if (func[0][0] == '/')
	// {
	// 	printf("exec slash/bin");
	// 	exec_slash(func, data, error);
	// }

}


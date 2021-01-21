/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:24:25 by frfrance          #+#    #+#             */
/*   Updated: 2020/12/02 21:08:34 by frfrance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

// allez dans des fichier donner
				// /Users/Kazuuma: is a directory
				// ./includes: is a directory
				// ../test: is a directory
void	path_error(char **func)
{
	if (error_bin == 1)
	{
		printf("minishell: %s : command not found\n", func[0]);
		
		return_valu = 127;
	}

}

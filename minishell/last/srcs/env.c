/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frfrance <frfrance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 03:56:11 by rqouchic          #+#    #+#             */
/*   Updated: 2020/12/31 00:10:59 by nsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_shell.h"

void ft_env_var(t_shell *data)
{
	int i;

	i = 0;
	while (data->copyenv[i])
	{
		ft_putstr_fd(data->copyenv[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:04:48 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/22 18:57:44 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_data(t_pipex *pipex, char **env, char **av, int ac)
{
	int	start;
	int	end;

	start = 3;
	end = ac - 2;
	if (ac < 5)
	{
		ft_printf("Mauvais nombres d'arguments!\n");
		exit(0);
	}
	else
	{
		pipex->cmd = ft_lstnew(env, av[2]);
		while (start <= end)
		{
			ft_lstadd_back(&pipex->cmd, ft_lstnew(env, av[start]));
			start++;
		}	
	}
}

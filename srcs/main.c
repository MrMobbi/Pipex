/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:04:07 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/21 12:03:54 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av, char **env)
{
	int	i = 0;
	t_data	data;

	data = ft_init_data(env, ac, av);
	printf("%s\n", data.cmd->cmd);
	while (data.cmd->path[i] != NULL)
	{
		printf("%s\n", data.cmd->path[i]);
		i++;
	}
	return (0);
}

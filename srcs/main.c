/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:04:07 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/23 15:54:36 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	ft_init_data(&pipex, env, av, ac);
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile < 0)
		return (ft_error(&pipex, av[1]));
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		return (ft_error(&pipex, av[ac - 1]));
	if (pipe(pipex.fd_pipe) < 0)
		return (0);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_first_child(pipex.cmd, &pipex, env);
	if (pipex.pid1 != 0)
		pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		ft_second_child(pipex.cmd->next, &pipex, env);
	ft_free_and_close(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}

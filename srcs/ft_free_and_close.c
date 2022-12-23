/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:56:21 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/23 14:54:34 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_and_close(t_pipex *pipex)
{
	ft_free(pipex);
	if (pipex->infile > 0)
		close(pipex->infile);
	if (pipex->outfile > 0)
		close(pipex->outfile);
	if (pipex->fd_pipe > 0)
	{
		close(pipex->fd_pipe[0]);
		close(pipex->fd_pipe[1]);
	}
}

void	ft_free(t_pipex *pipex)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (pipex->cmd != NULL)
	{
		while (pipex->cmd->all_path[i] != NULL)
		{
			free(pipex->cmd->all_path[i]);
			i++;
		}
		i = 0;
		while (pipex->cmd->option[i] != NULL)
		{
			free(pipex->cmd->option[i]);
			i++;
		}
		free(pipex->cmd->all_path);
		free(pipex->cmd->path);
		free(pipex->cmd->cmd);
		if (pipex->cmd->option != NULL)
			free(pipex->cmd->option);
		tmp = pipex->cmd;
		pipex->cmd = pipex->cmd->next;
		free(tmp);
	}
}

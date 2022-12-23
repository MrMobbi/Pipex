/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:35:08 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/23 15:29:01 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_child(t_list *cmd, t_pipex *pipex, char **env)
{
	dup2(pipex->fd_pipe[1], 1);
	close(pipex->fd_pipe[0]);
	dup2(pipex->infile, 0);
	execve(cmd->path, cmd->option, env);
}

void	ft_second_child(t_list *cmd, t_pipex *pipex, char **env)
{
	dup2(pipex->fd_pipe[0], 0);
	close(pipex->fd_pipe[1]);
	dup2(pipex->outfile, 1);
	execve(cmd->path, cmd->option, env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_utils_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:00:31 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/21 11:28:19 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ft_lstnew(char **env, char *cmd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->path = ft_get_path(env);
	new->cmd = ft_get_cmd(cmd);
	ft_get_full_path(new->path, cmd);
	new->next = NULL;
	return (new);
}

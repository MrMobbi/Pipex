/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_utils_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:00:31 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/22 16:00:09 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_list	*ft_lstnew(char **env, char *cmd)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->all_path = ft_get_all_path(env);
	new->cmd = ft_get_cmd(cmd);
	new->option = ft_get_option(cmd);
	ft_get_all_path_and_option(new->all_path, new->cmd);
	new->path = ft_get_path(new->all_path, cmd);
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*node;

	node = *lst;
	if (node == NULL)
		node->next = nw;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = nw;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_get_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:05:31 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/21 11:31:18 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **env)
{
	char	**path;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			str = ft_calloc(ft_strlen(env[i]) + 1, sizeof(char));
			if (!str)
				return (NULL);
			while (j < ft_strlen(env[i]))
			{
				str[j] = env[i][j];
				j++;
			}
		}
		i++;
	}
	path = ft_split(str + 5, ':');
	free(str);
	return (path);
}

void	ft_get_full_path(char **path, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], tmp);
		i++;
	}
	free(tmp);
}

char	*ft_get_cmd(char *cmd)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(cmd) + 1);
	if (!str)
		return (NULL);
	while (cmd[i] != '\0')
	{
		str[i] = cmd[i];
		i++;
	}
	return (str);
}

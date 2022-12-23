/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:05:31 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/23 16:14:54 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_all_path(char **env)
{
	char	**all_path;
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
	all_path = ft_split(str + 5, ':');
	free(str);
	return (all_path);
}

void	ft_get_all_path_and_option(char **all_path, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (all_path[i] != NULL)
	{
		all_path[i] = ft_strjoin(all_path[i], tmp);
		i++;
	}
	free(tmp);
}

char	*ft_get_cmd(char *cmd)
{
	char	*str;
	int		i;
	int		end;

	end = 0;
	i = 0;
	while (cmd[end] == ' ')
		end++;
	while (cmd[end] != '\0' && cmd[end] != ' ')
		end++;
	str = ft_calloc(sizeof(char), end + 1);
	if (!str)
		return (NULL);
	while (i < end)
	{
		str[i] = cmd[i];
		i++;
	}
	return (str);
}

char	*ft_get_path(char **all_path, char *cmd)
{
	char	*str;
	int		i;

	i = 0;
	while (all_path[i] != NULL)
	{
		if (access(all_path[i], X_OK) == 0)
		{
			str = ft_path_fund(all_path[i]);
			break ;
		}
		i++;
	}
	if (all_path[i] == NULL)
	{
		ft_printf("%s : %s\n", strerror(errno), cmd);
		exit (0);
		return (NULL);
	}
	return (str);
}

char	*ft_path_fund(char *path)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(path) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(path))
	{
	str[i] = path[i];
	i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:40:55 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/19 19:09:47 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_count_word(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!str[0] || !str)
		return (0);
	while (str[i + 1] != '\0')
	{
		if (str[i + 1] == c && str[i] != c)
			count++;
		i++;
	}
	if (str[i] != c)
		count++;
	return (count);
}

int	ft_strlen_c(const char *str, int index, char c)
{
	int	len;

	len = 0;
	while (str[index] != c && str[index] != '\0')
	{
		index++;
		len++;
	}
	return (len);
}

int	ft_find_next_word(const char *str, int index, char c)
{
	while (str[index] != c && str[index] != '\0')
		index++;
	while (str[index] == c && str[index] != '\0')
		index++;
	return (index);
}

char	**ft_split(char const *str, char c)
{
	int		index;
	int		i;
	char	**split;

	split = (char **)ft_calloc(ft_count_word(str, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	index = 0;
	i = 0;
	if (str[0] == c)
		index = ft_find_next_word(str, index, c);
	while (i < ft_count_word(str, c))
	{
		split[i] = ft_substr(str, index, ft_strlen_c(str, index, c));
		index = ft_find_next_word(str, index, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}

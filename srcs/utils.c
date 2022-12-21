/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:12:27 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/20 16:48:59 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str1[i] != '\0' && str2[i] != '\0' && i < n - 1)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*cal;
	size_t	i;

	i = 0;
	cal = malloc(count * size);
	if (!cal)
		return (NULL);
	while (i < count * size)
	{
		cal[i] = 0;
		i++;
	}
	return (cal);
}

char	*ft_substr(char const *str, int start, int len)
{
	char	*cpy;
	int		i;

	i = 0;
	if (start > ft_strlen(str))
	{
		cpy = malloc(sizeof(char) * 1);
		if (!cpy)
			return (NULL);
		cpy[0] = '\0';
		return (cpy);
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	cpy = ft_calloc(sizeof(char), len + 1);
	if (!cpy)
		return (NULL);
	while (i < len && str[start] != '\0')
	{
		cpy[i] = str[start];
		i++;
		start++;
	}
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{	
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

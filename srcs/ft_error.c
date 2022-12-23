/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:56:17 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/23 12:03:16 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(t_pipex *pipex, char *str)
{
	ft_free_and_close(pipex);
	ft_printf("%s : %s\n", strerror(errno), str);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:04:24 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/21 12:06:54 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_list {
	char			**path;
	char			*cmd;
	struct s_list	*next;
}					t_list;

typedef struct s_data {
	t_list	*cmd;
}			t_data;

//		##### Ft1_Init_Data.c #####
t_data	ft_init_data(char **env, char **av, int ac);

//		##### Ft1_Get_Path.c #####
char	**ft_get_path(char **env);
void	ft_get_full_path(char **path, char *cmd);
char	*ft_get_cmd(char *cmd);

//		##### Ft1_Utils_List.c #####
t_list	*ft_lstnew(char **env, char *cmd);

//		##### Ft1_Split.c #####
int		ft_count_word(const char *str, char c);
int		ft_strlen_c(const char *str, int index, char c);
int		ft_find_next_word(const char *str, int index, char c);
char	**ft_split(char const *str, char c);

//		##### Utils.c #####
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
char	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *str, int start, int len);
char	*ft_strjoin(char *s1, char *s2);

#endif

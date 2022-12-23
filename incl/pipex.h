/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:04:24 by mjulliat          #+#    #+#             */
/*   Updated: 2022/12/23 16:14:30 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_list {
	char			**all_path;
	char			*path;
	char			*cmd;
	char			**option;
	struct s_list	*next;
}					t_list;

typedef struct s_pipex {
	t_list	*cmd;
	int		infile;
	int		outfile;
	int		fd_pipe[2];
	int		pid1;
	int		pid2;
}			t_pipex;

//		##### Ft_Init_Data.c #####
void	ft_init_data(t_pipex *pipex, char **env, char **av, int ac);

//		##### Ft_Get_Path.c #####
char	**ft_get_all_path(char **env);
void	ft_get_all_path_and_option(char **path, char *cmd);
char	*ft_get_cmd(char *cmd);
char	*ft_get_path(char **all_path, char *cmd);
char	*ft_path_fund(char *path);

//		##### Ft_Get_Option.c #####
char	**ft_get_option(char *cmd);

//		##### Ft_Child.c #####
void	ft_first_child(t_list *cmd, t_pipex *pipex, char **env);
void	ft_second_child(t_list *cmd, t_pipex *pipex, char **env);

//		##### Ft_Error.c #####
int		ft_error(t_pipex *pipex, char *str);

//		##### Ft_Free_And_Close.c #####
void	ft_free_and_close(t_pipex *pipex);
void	ft_free(t_pipex *pipex);
void	ft_free_tab_str(char **str);

//		##### Ft_Utils_List.c #####
t_list	*ft_lstnew(char **env, char *cmd);
void	ft_lstadd_back(t_list **lst, t_list *nw);

//		##### Ft_Split.c #####
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

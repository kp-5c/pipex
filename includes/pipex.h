/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:58:44 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/25 11:33:12 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_pipe
{
	
	char		*cmd1_path;
	char		*cmd2_path;
	char		**cmd1_arg;
	char		**cmd2_arg;
	int			pipe[2]; 
	int		fd_in;
	int		fd_out;
	char	**paths;
	char	**path_cmd;
}	t_pipe;

void	ft_free_tab(char **tab);
char	*find_path(char *cmd, char **envp);
char	*find_path_2(char *cmd, char *paths);
void	ft_test_arg(int ac, char **av);
char *ft_management_arg(int ac, char *av, char **envp);
void ft_end_programme(t_pipe *pipex);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:20:51 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/24 14:05:58 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char *ft_management_arg(int ac, char *av, char **envp)
{
	char **cmd1;
	char *cmd2;

	(void)ac;
	
	cmd1 = ft_split(av, ' ');
	if(!cmd1)
		return(NULL);
	if (access(cmd1[0], X_OK) == 0)
		cmd2 = ft_strdup(cmd1[0]);
	else
		cmd2 = find_path(*cmd1, envp);
	ft_free_tab(cmd1);
	return(cmd2);
}


char	*find_path_2(char *cmd, char *paths)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(paths, "/");
	full_path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (access(full_path, X_OK) == 0)
		return (full_path);
	else
	{
		free(full_path);
		return (NULL);
	}
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = find_path_2(cmd, paths[i]);
		if (full_path != NULL)
		{
			ft_free_tab(paths);
			return(full_path);
		}
		free(full_path);
		i++;
	}
	return(ft_free_tab(paths), NULL);
}


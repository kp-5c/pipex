/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:08:01 by ebenoist          #+#    #+#             */
/*   Updated: 2025/08/01 14:18:29 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipes(t_pipe *pipex)
{
	int	i;

	pipex->nb_pipe = pipex->nb_cmd - 1;
	if (pipex->nb_pipe < 1)
		return ;
	pipex->fd = malloc(sizeof(int[2]) * pipex->nb_pipe);
	if (!pipex->fd)
	{
		perror("Error\n Malloc Pipe");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < pipex->nb_pipe)
	{
		if (pipe(pipex->fd[i]) == -1)
			perror("Error\nPipe");
		i++;
	}
}

void	ft_init_pipex_bonus(int ac, char **av, t_pipe *pipex)
{
	pipex->nb_cmd = ac - 3;
	pipex->fd_in = open(av[1], O_RDONLY);
	if (pipex->fd_in == -1)
	{
		perror("Error\nOpen File");
		pipex->fd_in = open("/dev/null", O_RDONLY);
	}
	pipex->fd_out = open(av[ac -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out == -1)
	{
		perror("Error\nClose File");
		ft_close_pipe_bonus(pipex);
		ft_end_programme_bonus(pipex);
		exit(1);
	}
	init_pipes(pipex);
	pipex->cmdi_arg = calloc(pipex->nb_cmd, sizeof(char **));
	pipex->cmdi_path = calloc(pipex->nb_cmd + 1, sizeof(char *));
	if (!pipex->cmdi_arg || !pipex->cmdi_path)
		perror("malloc pipex");
}

void	ft_creat_path(int ac, char **av, char **envp, t_pipe *pipex)
{
	size_t i;
	size_t j;
	size_t count;

	i = 2;
	count = ac - 1;
	while (i < count)
	{
		j = i - 2;
		pipex->cmdi_arg[j] = ft_split(av[i], ' ');
		if (!pipex->cmdi_arg[j] || !pipex->cmdi_arg[j][0] || pipex->cmdi_arg[j][0][0] == '\0')
		{
			ft_free_tab(pipex->cmdi_arg[j]);
			pipex->cmdi_arg[j]  = NULL;
			pipex->cmdi_path[j] = NULL;
		}
		else
		{
			pipex->cmdi_path[j] = ft_management_arg(&av[i][0], envp);
			if (!pipex->cmdi_path[j] || access(pipex->cmdi_path[j], X_OK) != 0)
			{
				free(pipex->cmdi_path[j]);
				pipex->cmdi_path[j] = NULL;
			}
		}
		i++;
	}
}

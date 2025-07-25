/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 08:06:50 by ebenoist          #+#    #+#             */
/*   Updated: 2025/07/25 13:24:07 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_creat_arg(int ac, char **av, char **envp, t_pipe *pipex)
{
	pipex->cmd1_arg = ft_split(av[2], ' ');
	pipex->cmd2_arg = ft_split(av[3], ' ');
	pipex->cmd1_path = ft_management_arg(ac, av[2], envp);
	pipex->cmd2_path = ft_management_arg(ac, av[3],envp);
	if(pipe(pipex->pipe) == -1)
		perror("Error\nPipe.Fd");
}

void ft_end_programme(t_pipe *pipex)
{
	if(pipex->cmd1_arg)
		ft_free_tab(pipex->cmd1_arg);
	if(pipex->cmd2_arg)
		ft_free_tab(pipex->cmd2_arg);
	if(pipex->cmd1_path)
		free(pipex->cmd1_path);
	if(pipex->cmd2_path)
		free(pipex->cmd2_path);
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;
	
	
	ft_test_arg(ac, av);
	ft_creat_arg(ac, av, envp, &pipex);
	pid_t	pid1;
	pid_t	pid2;
	
	pid1 = fork();
	if(pid1 == 0)
	{
		pipex.fd_in = open(av[1], O_RDONLY);
		if(pipex.fd_in < 0)
		{
			perror("Error\nInfile"), exit(1);
			ft_end_programme(&pipex);
			exit(1);
		}
		dup2(pipex.fd_in, STDIN_FILENO);
		dup2(pipex.pipe[1], STDOUT_FILENO);
		close(pipex.pipe[0]);
		close(pipex.fd_in);	
		execve(pipex.cmd1_path, pipex.cmd1_arg, envp);
		perror("execve cmd1 failed");
	}

	pid2 = fork();
	if (pid2 == 0)
	{
		pipex.fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(!pipex.fd_out)
		{
			perror("Error\nOutfile");
			ft_end_programme(&pipex);
			exit(1);
		}
		dup2(pipex.pipe[0], STDIN_FILENO);
		dup2(pipex.fd_out, STDOUT_FILENO);
		close(pipex.pipe[1]);
		close(pipex.fd_out);
		execve(pipex.cmd2_path, pipex.cmd2_arg, envp);
		perror("execve cmd1 failed");
	}
	
	
	
	ft_end_programme(&pipex);
}

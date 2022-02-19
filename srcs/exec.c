/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 03:54:52 by bifrah            #+#    #+#             */
/*   Updated: 2022/02/19 16:58:02 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child2(t_p *p)
{
	dup2(p->pipe_fd[READ], STDIN_FILENO);
	dup2(p->outfile, STDOUT_FILENO);
	close(p->pipe_fd[WRITE]);
	if (p->pipe_fd[READ] == -1 || p->outfile == -1)
		exit(EXIT_FAILURE);
	fillbincmd(p, p->argv[3]);
	if (p->binpath != NULL)
	{
		if (execve(p->binpath, p->cmd, p->envp) < 0)
		{
			perrorstring(p->cmd[0]);
			freecmdbin(p);
			exit(127);
		}
	}
	else if (p->binpath == NULL)
		ft_putstr_fd("Command not found : ""\n", 2);
	freecmdbin(p);
	exit(127);
}

void	child1(t_p *p)
{
	dup2(p->infile, STDIN_FILENO);
	dup2(p->pipe_fd[WRITE], STDOUT_FILENO);
	close(p->pipe_fd[READ]);
	if (p->infile == -1 || p->pipe_fd[WRITE] == -1)
		exit(EXIT_FAILURE);
	close(p->infile);
	fillbincmd(p, p->argv[2]);
	if (p->binpath != NULL)
	{
		if (execve(p->binpath, p->cmd, p->envp) < 0)
		{
			perrorstring(p->cmd[0]);
			freecmdbin(p);
			exit(127);
		}
	}
	else if (p->binpath == NULL)
		ft_putstr_fd("Command not found : ""\n", 2);
	freecmdbin(p);
	exit(127);
}

void	execcmds(t_p *p)
{
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(p->pipe_fd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Fork: "));
	else if (pid1 == 0)
		child1(p);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Fork: "));
	else if (pid2 == 0)
		child2(p);
	close(p->pipe_fd[READ]);
	close(p->pipe_fd[WRITE]);
	waitpid(pid1, &(p->exit_status), 0);
	p->exit_status = WEXITSTATUS(p->exit_status);
	close(p->infile);
	waitpid(pid2, &(p->exit_status), 0);
	p->exit_status = WEXITSTATUS(p->exit_status);
	close(p->outfile);
	return ;
}

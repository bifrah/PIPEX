/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:31:07 by bifrah            #+#    #+#             */
/*   Updated: 2022/02/19 18:47:22 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**getpath(t_p *p)
{
	int	i;

	i = 0;
	while (p->envp[i])
	{
		if (ft_strnstr(p->envp[i], "PATH=", 5) != NULL)
			return (ft_split(p->envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*findbin(t_p *p, char *cmd)
{
	int		i;
	char	**paths;
	char	*tmppath;
	char	*realpath;

	paths = getpath(p);
	if (paths)
	{
		i = 0;
		while (paths[i])
		{
			tmppath = ft_strjoin(paths[i], "/");
			realpath = ft_strjoin(tmppath, cmd);
			free(tmppath);
			if (access(realpath, F_OK) == 0)
			{
				free_split(paths);
				return (realpath);
			}
			free(realpath);
			i++;
		}
		free_split(paths);
	}
	return (printerror("Command not found: ", cmd, "\n"));
}

char	*checkcmd(t_p *p, char *cmd)
{
	if (cmd)
	{
		if (cmd[0] == '~' || cmd[0] == '.' || cmd[0] == '/')
		{
			if (access(cmd, F_OK) != 0)
				return (printerror("No such file or directory: ", cmd, "\n"));
			return (ft_strdup(cmd));
		}
		else
			return (findbin(p, cmd));
	}
	return (NULL);
}

void	fillbincmd(t_p *p, char *cmd)
{
	if (cmd)
	{
		if (cmd[0] != '\0')
		{
			p->cmd = ft_split(cmd, ' ');
			if (p->cmd != NULL)
				p->binpath = checkcmd(p, p->cmd[0]);
		}
	}
}

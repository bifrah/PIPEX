/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:20:35 by bifrah            #+#    #+#             */
/*   Updated: 2022/02/23 14:53:14 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	printtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	init_p(t_p *p, int argc, char **argv, char **envp)
{
	p->argc = argc;
	p->argv = argv;
	p->envp = envp;
	p->exit_status = 0;
	p->binpath = NULL;
	p->cmd = NULL;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_p	p;

	if (parse(argc, envp))
		return (ERROR);
	if (init_p(&p, argc, argv, envp))
		return (ERROR);
	p.infile = open(p.argv[1], O_RDONLY);
	if (p.infile == -1)
	{
		p.exit_status = 1;
		perrorstring01(argv[1]);
	}
	p.outfile = open(p.argv[4], O_CREAT | O_WRONLY | O_TRUNC, 00666);
	if (p.outfile == -1)
		perrorstring01(argv[4]);
	execcmds(&p);
	return (0);
}

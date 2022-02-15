/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:07:06 by bifrah            #+#    #+#             */
/*   Updated: 2022/02/15 16:11:30 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freecmdbin(t_p *p)
{
	if (p->cmd)
		free_split(p->cmd);
	if (p->binpath)
	{
		free(p->binpath);
		p->binpath = NULL;
	}
}

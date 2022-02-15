/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:07:29 by bifrah            #+#    #+#             */
/*   Updated: 2022/02/13 19:17:59 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse(int argc, char **envp)
{
	if (*envp == NULL)
	{
		perror("Good job, env -i ");
		return (ENV_ERROR);
	}
	if (argc != 5)
	{
		ft_putstr_fd("Input Error\n", 2);
		return (INPUT_ERROR);
	}
	return (0);
}

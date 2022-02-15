/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:05:05 by bifrah            #+#    #+#             */
/*   Updated: 2022/01/29 17:05:16 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

unsigned int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	lenforpath(const char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] == ':' || str[i])
	{
		i++;
		j++;
	}
	return (j);
}

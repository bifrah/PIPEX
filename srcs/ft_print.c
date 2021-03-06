/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:35:52 by bifrah            #+#    #+#             */
/*   Updated: 2022/02/23 16:01:32 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (s)
		write(fd, s, ft_strlen(s));
}

int	perrorstring01(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (EXIT_FAILURE);
}

int	perrorstring02(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (EXIT_FAILURE);
}

char	*printerror(char *str1, char *str2, char *str3)
{
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	return (NULL);
}

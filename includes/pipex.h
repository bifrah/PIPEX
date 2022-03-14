/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:22:51 by bifrah            #+#    #+#             */
/*   Updated: 2022/03/14 16:08:16 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_p {
	int		argc;
	char	**argv;
	char	**envp;
	int		exit_status;
	char	*binpath;
	char	**cmd;
	char	*tmpcmd1;
	int		infile;
	int		outfile;
	int		pipe_fd[2];
}			t_p;

void			ft_putstr_fd(char *s, int fd);
int				perrorstring01(char *str);
int				perrorstring02(char *str);
char			*printerror(char *str1, char *str2, char *str3);
unsigned int	ft_strlen(const char *str);
unsigned int	lenforpath(const char *str, int i);
char			*ft_strnstr(const char *large, const char *small,
					unsigned int size);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
void			free_split(char **array);
char			*ft_strdup(const char *src);
int				parse(int argc, char **envp);
int				init_p(t_p *p, int argc, char **argv, char **envp);
void			fillbincmd(t_p *p, char *cmd);
char			*checkcmd(t_p *p, char *cmd);
char			*findbin(t_p *p, char *cmd);
char			**getpath(t_p *p);
void			freecmdbin(t_p *p);
void			execcmds(t_p *p);
void			child1(t_p *p);
void			child2(t_p *p);

# define READ			0
# define WRITE			1

# define ERROR				1
# define INPUT_ERROR		2
# define ENV_ERROR			3
# define ACCESS_ERROR		4
# define INVALID_COMMAND	5
# define MALLOC_ERROR		6

#endif
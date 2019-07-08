/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:15:20 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/20 02:24:37 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

static	void	exec_pipe(char *cmd, t_env *env)
{
	char		**argv;
	int			i;

	argv = NULL;
	if (ft_strchr_quote(cmd, '>') || ft_strchr_quote(cmd, '<'))
		redirection_handler(cmd, env, 0);
	else
	{
		argv = ft_strsplit_quote(cmd, ' ');
		i = -1;
		while (argv[++i] != NULL)
			argv[i] = ft_strtrim_quote(argv[i]);
		if (!builtin_child(argv, env))
			exec_child(exec_errors(argv[0], env), argv, env);
	}
	ft_dbl_strdel(argv);
	exit(0);
}

static	void	pipe_parent(int i, int len, int *fd, int n)
{
	if (i <= len - 1 && i > 0)
	{
		close(fd[n - 1]);
		close(fd[n]);
	}
	wait(NULL);
}

static	void	pipe_childs(int i, int len, int *fd, int n)
{
	if (i == 0)
		pipe_duplication(fd, 0, 1, 1);
	else if (i > 0 && i < len - 1)
	{
		pipe_duplication(fd, n, n - 1, 0);
		pipe_duplication(fd, n + 1, n + 2, 1);
	}
	else if (i == len - 1)
		pipe_duplication(fd, n, n - 1, 0);
}

static	void	pipe_execution(char **line, int *fd, int len, t_env *env)
{
	pid_t		*child;
	int			i;
	int			n;

	child = childs_creation(len);
	i = 0;
	n = 0;
	while (i < len)
	{
		if (child[i] == 0)
		{
			pipe_childs(i, len, fd, n);
			exec_pipe(line[i], env);
		}
		else if (child[i] > 0)
			pipe_parent(i, len, fd, n);
		n = 2 * ++i - 1;
	}
	free(child);
}

void			pipe_handler(char *cmd, t_env *env)
{
	char		**line;
	int			*fd;
	int			len;

	line = ft_strsplit_quote(cmd, '|');
	if (line == NULL || (ft_chrlen_quote(cmd, '|') != ft_dbl_strlen(line) - 1))
	{
		ft_putendl_fd("21sh: syntax error near unexpected token `|'", 2);
		ft_strdel(&cmd);
		ft_dbl_strdel(line);
		return ;
	}
	len = ft_dbl_strlen(line);
	pipe_here_doc(line, env);
	fd = (int *)malloc(sizeof(int) * (len - 1) * 2);
	pipe_creation(len, fd);
	pipe_execution(line, fd, len, env);
	pipe_close_fd(len, fd);
	ft_dbl_strdel(line);
	ft_strdel(&cmd);
	free(fd);
}

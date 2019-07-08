/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:02:05 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 11:50:25 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vsh.h"
#include "../includes/builtins.h"
#include "../includes/termcap.h"

void			interpreter(char **argv, t_env *env)
{
	pid_t	child;
	char	*cmd;

	if ((cmd = exec_errors(argv[0], env)))
	{
		child = fork();
		if (child == 0)
			exec_child(cmd, argv, env);
		else
			wait(NULL);
		ft_strdel(&cmd);
	}
	else
		wait(NULL);
}

void			exec_child(char *cmd, char **argv, t_env *env)
{
	char	**environ;

	if (cmd == NULL)
		return ;
	environ = list_to_env(env);
	execve(cmd, argv, environ);
	ft_strdel(&cmd);
	ft_dbl_strdel(argv);
	ft_dbl_strdel(environ);
	exit(0);
}

static	int		file_exist(char *file, DIR *dir)
{
	struct dirent	*pdirent;

	while ((pdirent = readdir(dir)))
	{
		if (ft_strcmp(pdirent->d_name, ft_strlower(file)) == 0)
			return (1);
	}
	return (0);
}

char			*get_command(char *file, t_env *env)
{
	int		i;
	DIR		*dir;
	char	**paths;
	char	*cmd;

	if (!(paths = path_lexer(env)))
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		if ((dir = opendir(paths[i])))
		{
			if (file_exist(file, dir))
			{
				closedir(dir);
				cmd = ft_strjoinfree(ft_strjoin(paths[i], "/"), file);
				ft_dbl_strdel(paths);
				return (cmd);
			}
			closedir(dir);
		}
	}
	ft_dbl_strdel(paths);
	return (NULL);
}

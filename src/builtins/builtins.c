/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:37:22 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 13:24:27 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/vsh.h"

/*
** get current path
*/

char	*getpwd(void)
{
	char *path;

	path = ft_memalloc(PATHSIZE);
	getcwd(path, PATHSIZE);
	return (path);
}

/*
** check if the name of th command match one of the buitins
*/

int		is_builtin(char *cmd)
{
	if (ft_strequ(cmd, "cd") || ft_strequ(cmd, "echo") || ft_strequ(cmd, "env")
			|| ft_strequ(cmd, "setenv") || ft_strequ(cmd, "unsetenv") ||
			ft_strequ(cmd, "exit"))
		return (1);
	return (0);
}

void	exec_builtin(char **argv, t_env *env)
{
	if (ft_strequ(argv[0], "cd"))
		ft_cd(argv, env);
	else if (ft_strequ(argv[0], "echo"))
		ft_echo(argv);
	else if (ft_strequ(argv[0], "env"))
		ft_env(env);
	else if (ft_strequ(argv[0], "setenv"))
		ft_setenv(argv, env);
	else if (ft_strequ(argv[0], "unsetenv"))
		ft_unsetenv(argv, env);
	else
	{
		ft_dbl_strdel(argv);
		exit_shell(env);
	}
}

int		builtin_child(char **argv, t_env *env)
{
	expansions(argv);
	if (is_builtin(argv[0]))
	{
		exec_builtin(argv, env);
		return (1);
	}
	else
		return (0);
}

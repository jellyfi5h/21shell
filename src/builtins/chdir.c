/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 02:01:29 by aboukhri          #+#    #+#             */
/*   Updated: 2019/07/08 15:27:09 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

/*
**	print cd command error if there any
*/

static	void	chdir_err(char *arg)
{
	struct stat		sb;

	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	if (stat(arg, &sb) == -1)
		ft_putstr_fd("No such file or directory", 2);
	else if (!S_ISDIR(sb.st_mode))
		ft_putstr_fd("Not a directory", 2);
	else if (access(arg, R_OK) == -1 || access(arg, W_OK) == -1
			|| access(arg, X_OK) == -1)
		ft_putstr_fd("Permission denied.", 2);
	ft_putchar_fd('\n', 2);
}

/*
**	call chdir function for changing directory and change
**	PWD, OLDPWD values in the envirement
*/

static	void	change_dir(char *cd, t_env *env)
{
	char	*pwd;

	pwd = getpwd();
	if (chdir(cd) == 0)
	{
		insert_var("OLDPWD", pwd, env);
		pwd = getpwd();
		insert_var("PWD", pwd, env);
		free(pwd);
	}
	else
	{
		free(pwd);
		chdir_err(cd);
	}
}

/*
**	check if there are any flags and avoid them and return position
**	of the first argument after flags
*/

int				checkflags(char **args)
{
	int		i;
	int		j;
	char	t;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] != '-' || ft_strcmp(args[i], "-") == 0)
			return (i);
		j = 0;
		while (args[i][++j])
		{
			t = args[i][j];
			if ((t != 'L' && t != 'P' && t != '-') || (t == '-' && j > 1))
				return (i);
		}
	}
	return (i);
}

/*
**	check if there was their any other cases before changing
**						directory
*/

void			ft_cd(char **argv, t_env *env)
{
	int		pos;
	char	*cd;
	int		argc;

	pos = 1;
	argc = ft_dbl_strlen(argv + pos);
	if (argc > 1)
		ft_putendl_fd("cd: too many arguments.", 2);
	if (!argv[pos])
		cd = ft_strdup(ft_getenv("HOME", env));
	else if (ft_strcmp(argv[pos], "-") == 0 && argc == 1)
	{
		if ((cd = ft_strdup(ft_getenv("OLDPWD", env))))
			ft_putendl(cd);
	}
	else
		cd = ft_strdup(argv[pos]);
	if (cd != NULL)
	{
		change_dir(cd, env);
		free(cd);
	}
}

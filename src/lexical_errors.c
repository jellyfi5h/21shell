/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:50:15 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/20 04:14:00 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vsh.h"

char	*exec_errors(char *cmd, t_env *env)
{
	char	*path;

	if ((path = command_exists(cmd, env)))
	{
		if (access(path, X_OK) == -1)
			ft_putendl_fd("Permission denied.", 2);
		else
			return (path);
		ft_strdel(&path);
	}
	else
	{
		ft_putstr_fd("21sh: ", 2);
		if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
		{
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putstr_fd(cmd, 2);
		}
		else
		{
			ft_putstr_fd(cmd, 2);
			ft_putendl_fd(": command not found", 2);
		}
	}
	return (NULL);
}

char	*command_exists(char *cmd, t_env *env)
{
	struct stat sb;

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (stat(cmd, &sb) != -1)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	return (get_command(cmd, env));
}

void	exit_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

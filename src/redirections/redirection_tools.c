/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:17:09 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/20 04:47:41 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

void	trim_input(char **files, char **cmd_part)
{
	int		i;

	if (files != NULL)
	{
		i = -1;
		while (files[++i] != NULL)
			files[i] = ft_strtrim_quote(files[i]);
	}
	if (cmd_part != NULL)
	{
		i = -1;
		while (cmd_part[++i] != NULL)
			cmd_part[i] = ft_strtrim_quote(cmd_part[i]);
	}
}

int		ft_while_fd_aggregation(char *cmd, int i)
{
	if (((cmd[i] == '&' && (cmd[i - 1] == '<' || cmd[i - 1] == '>'))
		|| cmd[i] == '-' || ((cmd[i] == '>' || cmd[i] == '<')
		&& ((ft_isdigit(cmd[i - 1]) && (cmd[i - 2] == ' ' || i - 2 == 0))
		|| cmd[i + 1] == '&')) || (ft_isdigit(cmd[i]) && (((cmd[i - 1] == ' '
		|| i == 0) && (cmd[i + 1] == '>' || cmd[i + 1] == '<'))
		|| ((cmd[i - 1] == '&' || ft_isdigit(cmd[i - 1])) && (cmd[i + 1] == ' '
		|| cmd[i + 1] == '-' || cmd[i + 1] == '<' || cmd[i + 1] == '&'
		|| cmd[i + 1] == '>' || ft_isdigit(cmd[i + 1])
		|| cmd[i + 1] == '\0'))))))
		return (1);
	return (0);
}

void	pipe_here_doc(char **cmd, t_env *env)
{
	int		i;
	char	*ptr;

	i = 0;
	while (cmd[i] != NULL)
	{
		if ((ptr = ft_strchr_quote(cmd[i], '<')) && ptr[1] == '<')
		{
			if (redirection_handler(cmd[i], env, 1) == -1)
				cmd[i] = NULL;
			else
			{
				ptr[1] = '\0';
				cmd[i] = ft_strjoinfree(cmd[i], " .here_doc");
			}
		}
		i++;
	}
}

void	free_redirection(char **files, char **redirections, char **cmd)
{
	ft_dbl_strdel(cmd);
	ft_dbl_strdel(files);
	ft_dbl_strdel(redirections);
}

int		redirection_parent(void)
{
	int	status;

	wait(&status);
	if (status != 0)
		return (-1);
	return (0);
}

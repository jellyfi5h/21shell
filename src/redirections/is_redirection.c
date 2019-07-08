/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:54:27 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 05:03:54 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

int		ft_isfd_aggregation(char *cmd, int i)
{
	if ((ft_isdigit(cmd[i]) && (i == 0 || cmd[i - 1] == ' ')
		&& (cmd[i + 1] == '>' || cmd[i + 1] == '<')
		&& cmd[i + 2] == '&' && (ft_isdigit(cmd[i + 3]) || cmd[i + 3] == '-'))
		|| ((cmd[i] == '>' || cmd[i] == '<') && cmd[i + 1] == '&'
		&& (ft_isdigit(cmd[i + 2]) || cmd[i + 2] == '-')))
	{
		if (ft_isdigit(cmd[i + 2]) || (ft_isdigit(cmd[i + 3])
			&& cmd[i + 2] == '&'))
		{
			if (ft_isdigit(cmd[i + 2]))
				i += 2;
			else
				i += 3;
			while (ft_isdigit(cmd[++i]))
				;
			if (cmd[i] != ' ' && cmd[i] != '\0'
				&& cmd[i] != '>' && cmd[i] != '<' && cmd[i] != '-')
				return (0);
		}
		return (1);
	}
	return (0);
}

int		ft_isfile_redirection(char *cmd, int i)
{
	if (cmd[i] == '>' || cmd[i] == '<'
		|| ((ft_isdigit(cmd[i]) && (cmd[i - 1] == ' ' || i == 0))
		&& (cmd[i + 1] == '>' || cmd[i + 1] == '<'))
		|| (cmd[i] == '&' && (cmd[i + 1] == '>' || cmd[i + 1] == '<')))
		return (1);
	return (0);
}

int		ft_ismoving_fd(char *redirection)
{
	if ((ft_isdigit(redirection[0]) && (redirection[1] == '>'
		|| redirection[1] == '<') && redirection[2] == '&'
		&& ft_isdigit(redirection[3]) && redirection[4] == '-')
		|| ((redirection[0] == '>' || redirection[0] == '<')
		&& redirection[1] == '&' && ft_isdigit(redirection[2])
		&& redirection[3] == '-'))
		return (1);
	return (0);
}

int		ft_ishere_documents(char *cmd)
{
	if ((ft_isdigit(cmd[0]) && (cmd[1] == '<' && cmd[2] == '<'))
			|| (cmd[0] == '<' && cmd[1] == '<'))
		return (1);
	return (0);
}

int		ft_isclosing_fd(char *redirection, int fd)
{
	if (ft_strlen(redirection) >= 3 && ((redirection[3] == '-'
		&& redirection[2] == '&') || (redirection[2] == '-'
		&& redirection[1] == '&')))
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

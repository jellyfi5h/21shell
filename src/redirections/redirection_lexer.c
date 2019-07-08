/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_lexer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:23:51 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 06:38:40 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

static	char	*get_cmd_part(char *cmd_part, char *line, int *k, int *l)
{
	char		quote;
	int			i;
	int			j;

	i = *k;
	j = *l;
	cmd_part = ft_realloc(cmd_part, 1);
	if (line[i] == '"' || line[i] == '\'')
	{
		quote = line[i];
		cmd_part[j++] = line[i];
		while (line[++i] != quote && line[i] != '\0')
		{
			cmd_part = ft_realloc(cmd_part, 1);
			cmd_part[j++] = line[i];
		}
		cmd_part = ft_realloc(cmd_part, 1);
		(line[i] == quote) && (cmd_part[j++] = line[i++]);
	}
	else
		cmd_part[j++] = line[i++];
	*k = i;
	*l = j;
	return (cmd_part);
}

static	char	*get_file_name(char *file_name, char *cmd, int *k)
{
	char		new_file[NAME_MAX + 2];
	char		quote;
	int			i;
	int			j;

	i = *k;
	j = 0;
	while ((cmd[i] != ' ' && cmd[i] != '\0' && j < NAME_MAX
	&& cmd[i] != '>' && cmd[i] != '<') || cmd[i] == '"' || cmd[i] == '\'')
	{
		if (cmd[i] == '"' || cmd[i] == '\'')
		{
			quote = cmd[i];
			new_file[j++] = cmd[i];
			while (cmd[++i] != quote && cmd[i] != '\0')
				new_file[j++] = cmd[i];
			(cmd[i] == quote) && (new_file[j++] = cmd[i++]);
			break ;
		}
		new_file[j++] = cmd[i++];
	}
	*k = i;
	new_file[j++] = ' ';
	new_file[j] = '\0';
	return (ft_strjoinfree(file_name, new_file));
}

static	char	*get_redirection(char *redirection, char *cmd, int *k)
{
	char		new_redirection[6];
	int			i;
	int			j;

	i = *k;
	j = 0;
	while ((cmd[i] == '>' || cmd[i] == '<' || cmd[i] == '&'
			|| (ft_isdigit(cmd[i]) && ((cmd[i - 1] == ' ' || i == 0)
			&& (cmd[i + 1] == '>' || cmd[i + 1] == '<' || cmd[i + 1] == '&'))))
			&& j < 4)
		new_redirection[j++] = cmd[i++];
	new_redirection[j++] = ' ';
	new_redirection[j] = '\0';
	while (cmd[i] == ' ')
		i++;
	*k = i;
	redirection = ft_strjoinfree(redirection, new_redirection);
	return (redirection);
}

static	char	*get_file_aggr(char *redirection, char *cmd, int *k)
{
	char		*aggregation;
	int			i;
	int			j;

	i = *k;
	j = 0;
	aggregation = NULL;
	while (ft_while_fd_aggregation(cmd, i))
	{
		aggregation = ft_realloc(aggregation, 1);
		aggregation[j++] = cmd[i++];
	}
	*k = i;
	aggregation = ft_realloc(aggregation, 2);
	aggregation[j++] = ' ';
	aggregation[j] = '\0';
	redirection = ft_strjoinfree(redirection, aggregation);
	free(aggregation);
	return (redirection);
}

t_red			redirection_lexer(char *cmd)
{
	t_red		input;
	int			i;
	int			j;

	i = 0;
	j = 0;
	input.redirection = (char *)ft_memalloc(1);
	input.file_name = (char *)ft_memalloc(1);
	input.cmd_part = NULL;
	while (cmd[i] != '\0')
	{
		if (ft_isfd_aggregation(cmd, i))
		{
			input.redirection = get_file_aggr(input.redirection, cmd, &i);
			input.file_name = ft_strjoinfree(input.file_name, "* ");
		}
		else if (ft_isfile_redirection(cmd, i))
		{
			input.redirection = get_redirection(input.redirection, cmd, &i);
			input.file_name = get_file_name(input.file_name, cmd, &i);
		}
		else
			input.cmd_part = get_cmd_part(input.cmd_part, cmd, &i, &j);
	}
	return (input);
}

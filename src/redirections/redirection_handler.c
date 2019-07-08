/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:24:22 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/20 04:10:27 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

static	char	*is_error(char *redirection)
{
	char		*str;

	str = NULL;
	if (ft_chrlen(redirection, '&') >= 2 || ((ft_chrlen(redirection, '>') == 2
	|| ft_chrlen(redirection, '<') == 2 || (ft_strchr(redirection, '>') &&
	ft_strchr(redirection, '<'))) && ft_strchr(redirection, '&')))
	{
		if (redirection[0] != '&')
			str = "21sh: syntax error near unexpected token `&'";
		else if (ft_strchr(redirection, '>'))
			str = "21sh: syntax error near unexpected token '>'";
		else
			str = "21sh: syntax error near unexpected token '<'";
	}
	return (str);
}

static	char	*is_error_continue(char *files, char *redirection)
{
	char		*str;

	str = NULL;
	if (files == NULL)
		str = "21sh: syntax error near unexpected token 'newline'";
	else if (ft_chrlen(redirection, '>') == 3 ||
		(ft_chrlen(redirection, '<') == 2 && ft_strchr(redirection, '>')))
		str = "21sh: syntax error near unexpected token '>'";
	else if (ft_chrlen(redirection, '<') == 3 ||
			(ft_chrlen(redirection, '>') == 2 && ft_strchr(redirection, '<')))
		str = "21sh: syntax error near unexpected token '<'";
	else if (ft_chrlen(redirection, '>') >= 4)
		str = "21sh: syntax error near unexpected token '>>'";
	else if (ft_chrlen(redirection, '<') >= 4)
		str = "21sh: syntax error near unexpected token '<<'";
	else if (ft_chrlen(redirection, '&') >= 2)
		str = "21sh: syntax error near unexpected token `&'";
	else if (ft_strchr(redirection, '&') && (ft_strchr(redirection, '<')
		|| ft_strchr(redirection, '>')) &&
		ft_isdigit(redirection[0]) && redirection[3] == '\0')
		str = ft_strjoinfree(ft_strjoin("21sh: ", files),
				": ambiguous redirect");
	return (str);
}

static	int		redirection_errors(char **redirection, char **files)
{
	char		*str;
	int			i;

	i = -1;
	str = NULL;
	while (redirection[++i] != NULL)
	{
		str = is_error(redirection[i]);
		str = is_error_continue(files[i], redirection[i]);
		if (str != NULL)
		{
			ft_dbl_strdel(redirection);
			ft_dbl_strdel(files);
			ft_putendl_fd(str, 2);
			return (1);
		}
	}
	ft_dbl_strdel(redirection);
	ft_dbl_strdel(files);
	return (0);
}

int				redirection_handler(char *cmd, t_env *env, int here_doc)
{
	t_red		input;

	input = redirection_lexer(cmd);
	if (redirection_errors(ft_strsplit(input.redirection, ' '),
				ft_strsplit(input.file_name, ' ')))
	{
		free(input.redirection);
		free(input.file_name);
		free(input.cmd_part);
		return (-1);
	}
	if (redirection_parser(input, env, here_doc) == -1)
		return (-1);
	ft_strdel(&input.redirection);
	ft_strdel(&input.file_name);
	ft_strdel(&input.cmd_part);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 02:25:34 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 01:08:17 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vsh.h"
#include "../includes/builtins.h"

static	char	*dollar_value(char *chaine)
{
	char	*var;
	char	*str;
	int		i;
	char	*env;

	if ((i = ft_strchrindex(chaine, '/')) != -1)
		var = ft_strsub(chaine, 0, i - 2);
	else if ((i = ft_strchrindex(chaine, '=')) != -1)
		var = ft_strsub(chaine, 0, i - 1);
	else
		var = ft_strdup(chaine);
	if ((env = getenv(var)) != NULL)
		str = swap_strs(chaine, var, env);
	else
		str = ft_strjoin("$", chaine);
	ft_strdel(&var);
	return (str);
}

static	char	*dollar(char *arg)
{
	char	**chaines;
	int		j;
	char	*value;

	if (!(chaines = ft_strsplit(arg, '$')))
		return (NULL);
	arg = ft_remalloc(arg, 1);
	j = -1;
	while (chaines[++j])
	{
		if ((value = dollar_value(chaines[j])))
		{
			arg = ft_strjoinfree(arg, value);
			free(value);
		}
	}
	ft_dbl_strdel(chaines);
	return (arg);
}

static	char	*tilde_value(char *arg)
{
	char	*var;
	char	*str;
	int		i;

	if ((i = ft_strchrindex(arg, '/')) != -1)
		var = ft_strsub(arg, 1, i - 1);
	else
		var = ft_strdup(arg + 1);
	if (exist_file("/Users", var))
	{
		var = ft_strjoinfree(var, arg + ft_strlen(var) + 1);
		str = ft_strjoin("/Users/", var);
		ft_strdel(&var);
		return (str);
	}
	else
	{
		write(2, "Unknown user: ", 15);
		ft_putendl(arg);
		ft_strdel(&var);
		return (NULL);
	}
}

static	char	*tilde(char *arg)
{
	char	*str;
	char	*env;

	str = NULL;
	if (ft_strcmp(arg, "~+") == 0)
		str = getpwd();
	else if (ft_strcmp(arg, "~-") == 0 && (env = getenv("OLDPWD")) != NULL)
		str = ft_strdup(env);
	else if ((arg[1] == '/' || arg[1] == '\0') &&
			(env = getenv("HOME")) != NULL)
		str = ft_strjoin(env, arg + 1);
	else if (ft_isalpha(arg[1]))
		str = tilde_value(arg);
	ft_strdel(&arg);
	return (str);
}

/*
**	change all arguments that has $ or ~ sign to their new values
*/

int				expansions(char **args)
{
	int		i;
	char	*str;

	i = -1;
	while (args[++i])
	{
		if (args[i][0] == '~')
			args[i] = tilde(args[i]);
		else if (args[i][0] == '$')
			args[i] = dollar(args[i]);
		else if (args[i][0] == '"')
		{
			str = ft_strdup(args[i]);
			ft_strdel(&args[i]);
			args[i] = ft_strsub(str, 1, ft_strlen(str) - 2);
			ft_strdel(&str);
		}
		if (!args[i])
			return (-1);
	}
	return (1);
}

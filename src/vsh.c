/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:39:56 by mfetoui           #+#    #+#             */
/*   Updated: 2019/07/08 15:48:43 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vsh.h"
#include "../includes/builtins.h"

static	void	parser(char *cmd, t_env *env)
{
	int		i;
	char	**argv;
	char	*trim;

	if (ft_strchr_quote(cmd, '|'))
		pipe_handler(ft_strtrim(cmd), env);
	else if (ft_strchr_quote(cmd, '>') || ft_strchr_quote(cmd, '<'))
		redirection_handler(cmd, env, 0);
	else
	{
		argv = ft_strsplit_quote(cmd, ' ');
		i = -1;
		while (argv[++i] != NULL)
		{
			trim = ft_strtrim_quote(argv[i]);
			free(argv[i]);
			argv[i] = ft_strdup(trim);
			free(trim);
		}
		if (!builtin_child(argv, env))
			interpreter(argv, env);
		ft_dbl_strdel(argv);
	}
}

static	int		lexer(char *line, t_env *env)
{
	char	**cmd;
	int		j;

	enable_term();
	if ((cmd = ft_strsplit_quote(line, ';')) == NULL)
		return (-1);
	j = -1;
	while (cmd[++j])
		parser(cmd[j], env);
	ft_dbl_strdel(cmd);
	return (0);
}

void			set_line(int sig, t_env *env)
{
	static	struct s_termcap	info;

	if (sig)
		signal_effect(sig, &info);
	else
	{
		disable_term();
		if (get_col_pos() > 1)
			ft_putchar('\n');
		set_info_termcap(&info, get_prompt());
		ft_putstr(info.prompt);
		if (read_input(0, &info, env))
		{
			ft_putchar('\n');
			lexer(info.content, env);
		}
		else
			ft_putchar('\n');
		ft_strdel(&info.prompt);
		ft_strdel(&info.content);
	}
}

int				main(void)
{
	char		*term;
	extern char	**environ;
	t_env		*env;

	env = env_to_list(environ);
	signals_handling();
	if (!(term = getenv("TERM")))
		exit_error("TERM does not exist.");
	if (!(tgetent(NULL, term) > 0))
		exit_error("couldn't reach TERM database.");
	while (1)
		set_line(0, env);
	return (0);
}

void			exit_shell(t_env *env)
{
	free_env(env);
	enable_term();
	exit(0);
}

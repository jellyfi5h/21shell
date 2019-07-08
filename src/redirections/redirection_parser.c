/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:38:05 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/20 04:46:45 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"
#include "../../includes/termcap.h"

static	int		get_file_error(char *file)
{
	struct stat	filestate;

	if (stat(file, &filestate) == -1)
		ft_putendl_fd(ft_strjoin("21sh: ", ft_strjoin(file,
						": No such file or directory")), 2);
	else if (S_ISDIR(filestate.st_mode))
		ft_putendl_fd(ft_strjoin("21sh: ", ft_strjoin(file,
						": Is a directory")), 2);
	else if (access(file, filestate.st_mode) == -1)
		ft_putendl_fd(ft_strjoin("21sh: ", ft_strjoin(file,
						": Permission denied")), 2);
	exit(0);
}

static	int		get_file_fd(char *file, char *redirection)
{
	int			fd;
	char		*ptr;

	fd = -1;
	if ((ptr = ft_strchr(redirection, '>')) && ptr[1] == '>')
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if ((ptr = ft_strchr(redirection, '<')) && ptr[1] == '>')
		fd = open(file, O_RDWR | O_CREAT, 0666);
	else if ((ptr = ft_strchr(redirection, '>')))
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if ((ptr = ft_strchr(redirection, '<')) && ptr[1] != '<')
		fd = open(file, O_RDONLY);
	if (fd == -1)
		get_file_error(file);
	return (fd);
}

static	int		get_redirection_fd(int *file_fd, char *redirection)
{
	int			fd;

	fd = 0;
	if ((redirection[0] == '&' && redirection[1] == '>')
			|| (redirection[0] == '>' && redirection[1] == '&' &&
				redirection[2] != '-'))
	{
		dup2(*file_fd, 1);
		fd = 2;
	}
	else if (redirection[0] == '>')
		fd = 1;
	else if (redirection[0] == '<')
		fd = 0;
	else if (ft_isdigit(redirection[0]))
		fd = redirection[0] - '0';
	if (ft_strlen(redirection) >= 4 && redirection[2] == '&' &&
			ft_isdigit(redirection[3]))
		*file_fd = ft_atoi(&redirection[3]);
	else if (ft_strlen(redirection) >= 3 && redirection[1] == '&' &&
			ft_isdigit(redirection[2]))
		*file_fd = ft_atoi(&redirection[2]);
	return (ft_isclosing_fd(redirection, fd));
}

static	void	duplication(char **files, char **redirections)
{
	int			redirection_fd;
	int			file_fd;
	int			i;

	i = -1;
	file_fd = -1;
	redirection_fd = -1;
	while (redirections[++i] != NULL)
	{
		if (ft_ishere_documents(redirections[i]))
			file_fd = read_here_doc(files[i], 0);
		else if (!ft_isfd_aggregation(redirections[i], 0))
			file_fd = get_file_fd(files[i], redirections[i]);
		if ((redirection_fd = get_redirection_fd(&file_fd,
						redirections[i])) == -1)
			continue ;
		if (dup2(file_fd, redirection_fd) == -1)
		{
			ft_putendl_fd(ft_strjoin("21sh: ", ft_strjoinfree(ft_itoa(file_fd),
							": Bad file descriptor")), 2);
			exit(0);
		}
		if (ft_ismoving_fd(redirections[i]))
			close(file_fd);
	}
}

int				redirection_parser(t_red input, t_env *env, int here_doc_pipe)
{
	pid_t		child;
	char		**cmd;
	char		**files;
	char		**redirections;

	files = ft_strsplit_quote(input.file_name, ' ');
	redirections = ft_strsplit_quote(input.redirection, ' ');
	cmd = ft_strsplit_quote(input.cmd_part, ' ');
	trim_input(files, cmd);
	child = fork();
	if (child == 0)
	{
		if (here_doc_pipe == 1)
			read_here_doc(files[0], here_doc_pipe);
		else
			duplication(files, redirections);
		if (!builtin_child(cmd, env))
			exec_child(exec_errors(cmd[0], env), cmd, env);
		exit(0);
	}
	else if (child > 0 && redirection_parent() == -1)
		return (-1);
	free_redirection(files, redirections, cmd);
	return (0);
}

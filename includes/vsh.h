/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 00:55:32 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/20 04:47:32 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VSH_H
# define VSH_H

# include "../libft/libft.h"
# include "termcap.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/syslimits.h>
# include <dirent.h>

# define PATHSIZE 1024

typedef	struct	s_red
{
	char	*cmd_part;
	char	*redirection;
	char	*file_name;

}				t_red;

typedef	struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

/*
**	lexer
*/

void			set_line(int sig, t_env *env);
char			**path_lexer(t_env *env);

/*
**	signals
*/

void			handler(int sig);
void			signals_handling();
void			signal_effect(int sig, struct s_termcap *info);

/*
**	interpreter
*/

int				builtin_child(char **argv, t_env *env);
void			interpreter(char **argv, t_env *env);
char			*get_command(char *arg, t_env *env);
void			exec_child (char *cmd, char **argv, t_env *env);

/*
**	redirections
*/

int				redirection_handler(char *cmd, t_env *env, int here_doc_pipe);
t_red			redirection_lexer(char *cmd);
int				redirection_parser(t_red input, t_env *env, int here_doc_pipe);
int				ft_isfd_aggregation(char *cmd, int i);
int				ft_while_fd_aggregation(char *cmd, int i);
int				ft_isfile_redirection(char *cmd, int i);
int				ft_ishere_documents(char *cmd);
int				ft_ismoving_fd(char *redirection);
int				ft_isclosing_fd(char *redirection, int fd);
int				read_here_doc(char *keyword, int here_doc_pipe);
void			pipe_here_doc(char **cmd, t_env *env);
void			trim_input(char **files, char **cmd_part);
void			free_redirection(char **files, char **redirections, char **cmd);
int				redirection_parent(void);

/*
**	expansions
*/

int				expansions(char **args);
int				exist_file(char *path, char *file);
char			*swap_strs(char *path, char *str1, char *str2);

/*
**	pipe
*/

void			pipe_handler(char *cmd, t_env *env);
pid_t			*childs_creation(int len);
void			pipe_creation(int len, int *fd);
void			pipe_close_fd(int len, int *fd);
void			pipe_duplication(int *fd, int a, int b, int c);

/*
**	env list
*/

t_env			*env_to_list(char **environ);
char			**list_to_env(t_env *list);
void			insert_var(char *key, char *value, t_env *env);
void			delete_var(char *key, t_env *env);
char			*ft_getenv(char *key, t_env *env);
t_env			*new_env(char *key, char *value);
void			free_env(t_env *env);

/*
**	lexical_errors
*/

char			*exec_errors(char *cmd, t_env *env);
char			*command_exists(char *cmd, t_env *env);
void			exit_error(char *msg);
void			exit_shell(t_env *env);

/*
**	termacp
*/

void			end_of_life(char **line, struct s_cursor cursor, t_env *env);
int				read_input(const int fd, struct s_termcap *info, t_env *env);
char			*get_prompt(void);
void			set_info_termcap(struct s_termcap *info, char *prompt);
int				get_col_pos(void);

#endif

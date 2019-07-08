/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 05:39:36 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 01:24:59 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include "vsh.h"

# define PATHSIZE 1024

/*
**	builtins
*/

void	ft_cd(char **argv, t_env *env);
void	ft_env(t_env *env);
void	ft_echo(char **argv);
void	ft_unsetenv(char **argv, t_env *env);
void	ft_setenv(char **argv, t_env *env);

/*
**	helpful functions
*/

int		is_builtin(char *cmd);
int		exists_var(char *var);
char	*getpwd();
void	exec_builtin(char **argv, t_env *env);

#endif

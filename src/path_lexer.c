/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:53:40 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 01:21:39 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vsh.h"

char	**path_lexer(t_env *env)
{
	char	*var;
	char	**path;

	if ((var = ft_getenv("PATH", env)))
	{
		path = ft_strsplit(var, ':');
		return (path);
	}
	return (NULL);
}

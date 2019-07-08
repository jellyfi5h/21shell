/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlb_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfetoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:02:09 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 12:59:33 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	doublestrlen(char **argv)
{
	int		i;

	i = -1;
	if (argv == NULL)
		return (1);
	while (argv[++i])
		;
	return (i);
}

char		**dbl_strdup(char **env)
{
	char	**new;
	int		i;

	new = (char**)malloc(sizeof(*new) * (doublestrlen(env) + 1));
	i = -1;
	while (env[++i])
		new[i] = ft_strdup(env[i]);
	new[i] = NULL;
	return (new);
}

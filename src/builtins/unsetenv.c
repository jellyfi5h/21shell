/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:12:54 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/20 04:37:42 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

void	ft_unsetenv(char **argv, t_env *env)
{
	int		i;
	int		argc;

	argc = ft_dbl_strlen(argv);
	if (argc == 1)
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else
	{
		i = 0;
		while (argv[++i])
			delete_var(argv[i], env);
	}
}

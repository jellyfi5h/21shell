/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:08:46 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 11:09:03 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

void	ft_setenv(char **argv, t_env *env)
{
	int		argc;

	argc = ft_dbl_strlen(argv);
	if (argc > 3)
		ft_putendl_fd("setenv: Too many arguments.", 2);
	else if (argc == 1)
		ft_env(env);
	else
	{
		if (!str_isalnum(argv[1]))
		{
			ft_putstr_fd("setenv: Variable name must contain"
					" alphanumeric characters.\n", 2);
		}
		else
			insert_var(argv[1], argv[2], env);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:36:21 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 09:00:20 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

void	ft_env(t_env *env)
{
	char	*var;
	t_env	*lst;

	if (env == NULL)
		return ;
	lst = env;
	while (lst)
	{
		var = ft_strjoinfree(ft_strjoin(lst->key, "="), lst->value);
		ft_putendl(var);
		ft_strdel(&var);
		lst = lst->next;
	}
}

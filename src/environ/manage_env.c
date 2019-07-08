/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 09:07:56 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 12:11:03 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

void	insert_var(char *key, char *value, t_env *env)
{
	t_env	*lst;

	if (key == NULL)
		return ;
	if (value == NULL)
		value = (char*)ft_memalloc(1);
	lst = env;
	while (lst->next)
	{
		if (ft_strequ(lst->key, key))
		{
			free(lst->value);
			lst->value = ft_strdup(value);
			return ;
		}
		lst = lst->next;
	}
	if (ft_strequ(lst->key, key))
	{
		free(lst->value);
		lst->value = ft_strdup(value);
	}
	else
		lst->next = new_env(key, value);
}

void	delete_var(char *key, t_env *env)
{
	t_env	**lst;
	t_env	*current;

	lst = &env;
	while (*lst)
	{
		current = *lst;
		if (ft_strequ(current->key, key))
		{
			*lst = current->next;
			free(current->key);
			free(current->value);
			free(current);
			break ;
		}
		lst = &(current->next);
	}
}

char	*ft_getenv(char *key, t_env *env)
{
	t_env	*lst;

	lst = env;
	while (lst)
	{
		if (ft_strequ(key, lst->key))
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:29:21 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 11:21:01 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

t_env			*new_env(char *key, char *value)
{
	t_env	*new;

	new = (t_env*)malloc(sizeof(t_env));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

static	t_env	get_key_value(char *env)
{
	int		index;
	t_env	info;

	index = ft_strchrindex(env, '=');
	info.key = ft_strsub(env, 0, index - 1);
	info.value = ft_strdup(env + index);
	return (info);
}

static	int		env_len(t_env *env)
{
	int		len;

	len = 0;
	while (env)
	{
		env = env->next;
		len++;
	}
	return (len);
}

t_env			*env_to_list(char **environ)
{
	t_env	*ptr;
	t_env	*head;
	t_env	info;
	int		i;

	i = -1;
	head = NULL;
	while (environ[++i])
	{
		info = get_key_value(environ[i]);
		if (!head)
		{
			head = new_env(info.key, info.value);
			ptr = head;
		}
		else
		{
			ptr->next = new_env(info.key, info.value);
			ptr = ptr->next;
		}
	}
	return (head);
}

char			**list_to_env(t_env *env)
{
	char	**env_char;
	int		i;
	t_env	*list;

	list = env;
	env_char = (char**)malloc(sizeof(char*) * (env_len(list) + 1));
	i = 0;
	while (list)
	{
		env_char[i] = ft_strjoinfree(ft_strjoin(list->key, "="), list->value);
		i++;
		list = list->next;
	}
	env_char[i] = 0;
	return (env_char);
}

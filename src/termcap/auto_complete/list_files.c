/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:31:40 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/12 21:44:44 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

char		*transform_filename(char *file)
{
	int		i;
	char	*new;

	if (file == NULL)
		return (NULL);
	new = ft_strdup(file);
	i = -1;
	while (new[++i])
	{
		if (new[i] == ' ' && new[i - 1] != '\\')
			edit_str(&new, "\\", i);
	}
	return (new);
}

t_file		*new_file(char *name, char type, int index, int nav)
{
	t_file	*new;
	char	*filename;

	filename = transform_filename(name);
	new = (t_file*)malloc(sizeof(t_file));
	new->name = (type == 4) ? ft_strjoin(filename, "/") : ft_strdup(filename);
	new->type = (type == 4) ? 'd' : 'f';
	new->index = index;
	new->nav = nav;
	new->next = NULL;
	free(filename);
	return (new);
}

t_file		*file_join(t_file *begin, t_file *end)
{
	t_file	*head;

	if (begin == NULL)
		return (end);
	if (end == NULL)
		return (begin);
	head = begin;
	while (head->next)
		head = head->next;
	head->next = end;
	return (begin);
}

int			file_len(t_file *file)
{
	t_file	*ptr;
	int		len;

	len = 0;
	ptr = file;
	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

void		free_file(t_file *file)
{
	t_file	*tmp;

	while (file)
	{
		tmp = file;
		file = file->next;
		free(tmp->name);
		free(tmp);
	}
}

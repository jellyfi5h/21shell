/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:13:35 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 12:18:39 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

int		file_exists(t_file *file, char *name)
{
	while (file)
	{
		if (ft_strcmp(file->name, name) == 0)
			return (1);
		file = file->next;
	}
	return (0);
}

void	sort_files(t_file **file)
{
	t_file	*head;
	t_file	*sort;
	t_file	swp;

	head = *file;
	while (head->next)
	{
		sort = head->next;
		while (sort)
		{
			if (ft_strcmp(head->name, sort->name) > 0)
			{
				swp = (t_file){sort->index, sort->name,
					sort->type, sort->nav, NULL};
				sort->name = ft_strdup(head->name);
				sort->type = head->type;
				free(head->name);
				head->name = ft_strdup(swp.name);
				head->type = swp.type;
			}
			sort = sort->next;
		}
		head = head->next;
	}
}

void	put_files(t_file *files)
{
	while (files)
	{
		ft_putendl(files->name);
		files = files->next;
	}
}

int		column_size(t_file *file)
{
	int		cl;

	cl = 0;
	while (file)
	{
		if (ft_strlen(file->name) > cl)
			cl = ft_strlen(file->name);
		file = file->next;
	}
	return (cl + 2);
}

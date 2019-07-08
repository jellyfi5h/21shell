/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_similar_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:53:47 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 12:18:04 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vsh.h"
#include "../../../includes/termcap.h"

static	void	save_files(t_file **head, t_file **ptr,
		struct dirent *pdirent, int index)
{
	if (!(*head))
	{
		*head = new_file(pdirent->d_name, (char)pdirent->d_type, index, 0);
		*ptr = *head;
	}
	else
	{
		(*ptr)->next = new_file(pdirent->d_name,
				(char)pdirent->d_type, index, 0);
		(*ptr) = (*ptr)->next;
	}
}

static	t_file	*similar_files(DIR *dir, char *start, t_file *files)
{
	struct dirent	*pdirent;
	int				len;
	t_file			*head;
	t_file			*ptr;
	static	int		index;

	(files == NULL) && (index = 1);
	head = NULL;
	ptr = NULL;
	len = ft_strlen(start);
	while ((pdirent = readdir(dir)))
	{
		if (ft_strncmp(start, pdirent->d_name, len) == 0 && !file_exists(files,
		pdirent->d_name) && (pdirent->d_name[0] != '.' || start[0] == '.'))
		{
			save_files(&head, &ptr, pdirent, index);
			index++;
		}
	}
	closedir(dir);
	return (head);
}

t_file			*file_complete(char *filename, char **path)
{
	DIR		*dir;
	t_file	*head;
	int		i;

	if (path == NULL)
		return (NULL);
	head = NULL;
	i = -1;
	while (path[++i])
	{
		if ((dir = opendir(path[i])))
			head = file_join(head, similar_files(dir, filename, head));
	}
	if (head != NULL)
		sort_files(&head);
	ft_dbl_strdel(path);
	return (head);
}

t_file			*insert_files(char *line, int pos,
		struct s_autocomplete complete)
{
	char	**paths;
	char	buff[2048];
	int		index;

	paths = NULL;
	index = get_word_index(line, pos);
	if (complete.filename[0] == '.' || (complete.path != NULL
	&& complete.path[0] == '.') || index > 0)
	{
		getcwd(buff, PATHSIZE);
		paths = (char**)ft_memalloc(sizeof(*paths) * 2);
		paths[0] = (complete.path != NULL) ?
		ft_strjoinfree(ft_strjoin(buff, "/"), complete.path) : ft_strdup(buff);
	}
	else if (index == 0 && complete.path == NULL &&
			ft_strlen(complete.filename) > 0)
		paths = ft_strsplit(getenv("PATH"), ':');
	else if (complete.path != NULL && complete.path[0] == '/')
	{
		paths = (char**)ft_memalloc(sizeof(*paths) * 2);
		paths[0] = ft_strdup(complete.path);
	}
	return (file_complete(complete.filename, paths));
}

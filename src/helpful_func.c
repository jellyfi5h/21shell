/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:59:08 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 01:08:17 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vsh.h"

int		exist_file(char *path, char *file)
{
	DIR				*dir;
	struct dirent	*pdirent;

	if ((dir = opendir(path)))
	{
		while ((pdirent = readdir(dir)))
		{
			if (ft_strcmp(pdirent->d_name, file) == 0)
			{
				closedir(dir);
				return (1);
			}
		}
		closedir(dir);
	}
	return (0);
}

char	*swap_strs(char *path, char *str1, char *str2)
{
	int		index;
	int		len;
	char	*res;

	len = ft_strlen(str1);
	if ((index = ft_strstrindex(path, str1)) != -1)
	{
		res = ft_strjoinfree(ft_strjoinfree(ft_strsub(path, 0, index)
					, str2), path + index + len);
		return (res);
	}
	else
		return (NULL);
}

int		key_is_str(char *buff)
{
	int i;

	i = -1;
	while (buff[++i])
	{
		if ((buff[i] < 32 || buff[i] > 126) && buff[i] != '\n')
			return (0);
	}
	return (1);
}

/*
** edit string by adding buffer to line in the given position
*/

void	edit_str(char **line, char *copy, int pos)
{
	char	*begin;
	char	*end;
	int		len;

	len = ft_strlen(*line);
	if (pos > len)
		pos--;
	begin = ft_strsub(*line, 0, pos);
	end = ft_strjoin(copy, *line + pos);
	free(*line);
	*line = ft_strjoin(begin, end);
	free(begin);
	free(end);
}

/*
** delete a char of string in a giving position
*/

char	*delete_char(char *str, int pos)
{
	while (str[pos])
	{
		str[pos] = str[pos + 1];
		pos++;
	}
	return (str);
}

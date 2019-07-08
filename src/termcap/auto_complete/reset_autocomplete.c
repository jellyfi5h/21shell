/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_autocomplete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 00:47:37 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/18 08:05:59 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

void					set_autocomplete(struct s_termcap *info)
{
	char					*word;
	int						index;

	info->complete.stop = 1;
	info->complete.files = NULL;
	info->complete.len_files = 0;
	word = str_word_index(info->line, line_index(info->line, info->cursor));
	if ((index = ft_strrchrindex(word, '/')) != -1)
	{
		info->complete.filename = ft_strdup(word + index);
		info->complete.path = ft_strsub(word, 0, index);
	}
	else
	{
		info->complete.filename = ft_strdup(word);
		info->complete.path = NULL;
	}
	info->complete.check_first = 0;
	free(word);
}

void					free_autocomplete(struct s_autocomplete *complete)
{
	if (complete->files != NULL)
		free_file(complete->files);
	if (complete->filename != NULL)
		free(complete->filename);
	if (complete->path)
		free(complete->path);
}

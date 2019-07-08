/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:29:47 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/10 17:57:36 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

/*
** dalete the selected text in case tcut the text
*/

static	void	delete_selected_line(char **line, int begin, int end)
{
	char	*first;
	char	*last;

	first = ft_strsub(*line, 0, begin);
	last = ft_strsub(*line, end, ft_strlen(*line));
	free(*line);
	*line = ft_strjoin(first, last);
	free(first);
	free(last);
}

void			copy_line(char **copy, char *select)
{
	free(*copy);
	if (select)
	{
		*copy = ft_strdup(select);
		free(select);
	}
}

void			cut_line(char **line, struct s_cursor *cursor, int pos)
{
	int				begin;
	int				end;
	int				index;
	struct s_cursor	new;

	index = line_index(*line, *cursor);
	if (pos > 0)
	{
		begin = index - pos;
		end = index + 1;
		new = cursor_index(*line, begin, cursor->prompt);
		cursor->co = new.co;
		if (cursor->li > new.li)
			tputs(tgoto(tgetstr("UP", NULL), 0, cursor->li - new.li)
			, 1, err_putchar);
		cursor->li = new.li;
	}
	else
	{
		begin = index;
		end = index + (pos * -1) + 1;
	}
	delete_selected_line(line, begin, end);
}

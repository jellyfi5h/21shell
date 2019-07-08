/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:12:10 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/18 08:01:30 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

/*
** remove selection mode
*/

static	void	unselect_mode(char *line, struct s_cursor cursor)
{
	clear_all_lines(cursor);
	ft_putstr(line);
	cursor_reset(line, cursor);
}

/*
**	in case the cursor was in the last index of line
**	it should move it one character left
*/

static	char	*select_position(struct s_termcap *info)
{
	int		index;
	char	*buff;

	buff = NULL;
	index = line_index(info->line, info->cursor);
	if (index == ft_strlen(info->line) && index > 0)
	{
		cursor_navigate_left(info->line, &info->cursor);
		cursor_reset(info->line, info->cursor);
		index--;
	}
	if (index >= 0)
	{
		buff = (char*)ft_memalloc(2);
		buff[0] = info->line[index];
	}
	return (buff);
}

/*
**	select text left and right and copy(c), cut(k)
*/

void			select_text(struct s_termcap *info)
{
	char	buff[5];
	char	*select;
	int		pos;
	int		key;

	pos = 0;
	select = select_position(info);
	ft_bzero(buff, 5);
	while (read(0, buff, 4) > 0)
	{
		key = *((int*)buff);
		if (key == K_LEFT)
			pos += select_left(info->line, &select, &info->cursor, pos);
		else if (key == K_RIGHT)
			pos += select_right(info->line, &select, &info->cursor, pos);
		else if (key == 'c' || key == 'k')
			copy_line(&info->select, select);
		if (key == 'k')
			cut_line(&info->line, &info->cursor, pos);
		if (key != K_LEFT && key != K_RIGHT)
			break ;
		ft_bzero(buff, 5);
	}
	unselect_mode(info->line, info->cursor);
}

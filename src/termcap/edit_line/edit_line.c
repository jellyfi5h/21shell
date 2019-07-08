/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 03:22:59 by aboukhri          #+#    #+#             */
/*   Updated: 2019/07/08 16:04:14 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vsh.h"

/*
** write in line at the position giving of cursor (col, row)
*/

void	write_line(char *line, struct s_cursor cursor)
{
	struct winsize	ws;
	int				pos;

	pos = line_index(line, cursor);
	ioctl(0, TIOCGWINSZ, &ws);
	tputs(tgetstr("cd", NULL), 1, err_putchar);
	while (line[pos])
	{
		ft_putchar(line[pos]);
		if (line[pos] == '\n' || cursor.co == ws.ws_col - 1)
		{
			if (cursor.co == ws.ws_col - 1
					&& line[pos + 1] == '\n' && line[pos] != '\n')
				tputs(tgetstr("do", NULL), 1, err_putchar);
			cursor.co = 0;
		}
		else
			cursor.co++;
		pos++;
	}
}

void	print_line(char **line, char *copy, struct s_cursor *cursor)
{
	int				pos;
	struct s_cursor	index;

	if (!copy)
		return ;
	(*line == NULL) && (*line = (char*)ft_memalloc(1));
	pos = line_index(*line, *cursor);
	edit_str(line, copy, pos);
	write_line(*line, *cursor);
	pos += ft_strlen(copy);
	index = cursor_index(*line, pos, cursor->prompt);
	if (index.co == 0 && pos == ft_strlen(*line))
		tputs(tgetstr("do", NULL), 1, err_putchar);
	cursor->co = index.co;
	cursor->li = index.li;
	cursor_reset(*line, *cursor);
}

/*
** paste line in case buffer length are bigger than 3 read by 1000 from input
*/

void	paste_line(char **line, struct s_cursor *cursor, char *buff)
{
	char	*paste;
	char	text[1001];
	int		end;

	paste = ft_strdup(buff);
	if (ft_strlen(paste) > 3)
	{
		end = 0;
		while (1 || (end = read(0, text, 1000)) > 0)
		{
			text[end] = '\0';
			if (end > 0 && key_is_str(text))
				paste = ft_strjoinfree(paste, text);
			else
				break ;
			ft_bzero(text, end);
		}
	}
	print_line(line, paste, cursor);
	free(paste);
}

void	edit_keys(int key, struct s_termcap *info)
{
	if (key == K_UP || key == K_DOWN)
		history_keys(info, key);
	else if (key == CTRL_L)
		reset_screen(*info);
	else if (key == CTRL_P)
		paste_line(&info->line, &info->cursor, info->select);
	else if (key == CTRL_T)
		select_text(info);
	else if (key == K_BACKSPACE)
		delete_key(&info->line, &info->cursor, 1);
}

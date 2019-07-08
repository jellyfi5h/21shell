/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate_cursor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:43:49 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 02:28:27 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

void	cursor_navigate_right(char *line, struct s_cursor *cursor)
{
	int				nbrli;
	struct winsize	ws;
	int				pos;
	int				len;

	len = ft_strlen(line);
	ioctl(0, TIOCGWINSZ, &ws);
	pos = line_index(line, *cursor);
	nbrli = last_cursor(line, cursor->prompt).li;
	if (((cursor->li < nbrli || pos + 1 == len)
	&& cursor->co == ws.ws_col - 1) || line[pos] == '\n')
	{
		cursor->li++;
		cursor->co = 0;
		tputs(tgetstr("do", NULL), 1, err_putchar);
	}
	else if (pos < len)
		cursor->co++;
}

void	cursor_navigate_left(char *line, struct s_cursor *cursor)
{
	struct winsize	ws;
	int				pos;

	pos = line_index(line, *cursor);
	ioctl(0, TIOCGWINSZ, &ws);
	if (cursor->li > 1)
	{
		if (cursor->co == 0)
		{
			tputs(tgetstr("up", NULL), 1, err_putchar);
			cursor->li--;
			if (line[pos - 1] == '\n')
				cursor->co = cursor_index(line, pos - 1, cursor->prompt).co;
			else
				cursor->co = ws.ws_col - 1;
		}
		else
			cursor->co--;
	}
	else if (cursor->co > cursor->prompt)
		cursor->co--;
}

/*
** return to the begining of the line || to the end
*/

void	home_end_keys(int key, struct s_termcap *info)
{
	struct s_cursor	last;

	if (key == K_HOME)
	{
		if (info->cursor.li > 1)
			tputs(tgoto(tgetstr("UP", NULL), 0,
			info->cursor.li - 1), 1, err_putchar);
		info->cursor.co = info->cursor.prompt;
		info->cursor.li = 1;
	}
	else
	{
		last = last_cursor(info->line, info->cursor.prompt);
		if (last.li > info->cursor.li)
			tputs(tgoto(tgetstr("DO", NULL), 0,
			last.li - 1), 1, err_putchar);
		info->cursor.li = last.li;
		info->cursor.co = last.co;
	}
}

/*
** navigate cursor forward and backward trough right and left arrow keys
*/

void	navigate_keys(int key, struct s_termcap *info)
{
	if (key == K_RIGHT)
		cursor_navigate_right(info->line, &info->cursor);
	else if (key == K_LEFT)
		cursor_navigate_left(info->line, &info->cursor);
	else if (key == ALT_LEFT)
		navigate_previous_word(info->line, &info->cursor);
	else if (key == ALT_RIGHT)
		navigate_next_word(info->line, &info->cursor);
	else if (key == ALT_UP || key == ALT_DOWN)
		navigate_lines(key, info);
	else if (key == K_HOME || key == K_END)
		home_end_keys(key, info);
}

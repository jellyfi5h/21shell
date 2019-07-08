/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:14:52 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 02:29:23 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

static	int	return_co(char *line, int pos, int co, int prompt)
{
	int		index;

	if (line[pos - 1] == '\n')
	{
		index = cursor_index(line, pos - 1, prompt).co;
		if (co >= index)
			return (index);
		else
			return (co);
	}
	else
		return (co);
}

static	int	next_line(char *line, int pos, int prompt)
{
	struct winsize	ws;
	int				end;
	struct s_cursor	index;
	int				co;

	ioctl(0, TIOCGWINSZ, &ws);
	end = pos + ws.ws_col;
	index = cursor_index(line, pos, prompt);
	co = index.co;
	while (pos < end && line[pos])
	{
		if (line[pos] == '\n' || index.co == ws.ws_col - 1)
		{
			if (prompt == 0)
				return (index.co);
			index.co = 0;
			prompt = 0;
		}
		else if (co == index.co && prompt == 0)
			return (co);
		else
			index.co++;
		pos++;
	}
	return (index.co);
}

static	int	previous_line(char *line, int pos, int prompt)
{
	struct winsize	ws;
	int				end;
	struct s_cursor	index;
	int				co;

	ioctl(0, TIOCGWINSZ, &ws);
	end = pos - ws.ws_col;
	index = cursor_index(line, pos, prompt);
	co = index.co;
	if (index.li == 2 && co < prompt)
		return (prompt);
	while (pos > end && pos > 0)
	{
		if (index.co == 0 && index.li > 1)
			return (return_co(line, pos, co, prompt));
		else
			index.co--;
		pos--;
	}
	return (index.co);
}

/*
**	navigate between lines using CTRL+U || CTRL+D
*/

void		navigate_lines(int key, struct s_termcap *info)
{
	struct s_cursor	last;
	int				pos;

	pos = line_index(info->line, info->cursor);
	last = last_cursor(info->line, info->cursor.prompt);
	if (key == ALT_DOWN && info->cursor.li < last.li)
	{
		info->cursor.li++;
		info->cursor.co = next_line(info->line, pos, info->cursor.prompt);
		tputs(tgetstr("do", NULL), 1, err_putchar);
	}
	else if (key == ALT_UP && info->cursor.li > 1)
	{
		info->cursor.li--;
		info->cursor.co = previous_line(info->line, pos, info->cursor.prompt);
		tputs(tgetstr("up", NULL), 1, err_putchar);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 02:11:22 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/17 21:32:32 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

/*
** get index of the last line and cursor in the line
*/

struct	s_cursor	last_cursor(char *line, int prompt)
{
	struct s_cursor	cursor;
	int				i;
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	cursor = (struct s_cursor){prompt, 1, prompt};
	i = -1;
	while (line[++i])
	{
		cursor.co++;
		if (line[i] == '\n' || cursor.co == ws.ws_col)
		{
			cursor.li++;
			cursor.co = 0;
		}
	}
	return (cursor);
}

/*
** return the position of cursor by the index of the line given
*/

struct	s_cursor	cursor_index(char *line, int pos, int prompt)
{
	int				i;
	struct s_cursor	index;
	struct winsize	ws;

	i = 0;
	index.co = prompt;
	index.li = 1;
	ioctl(0, TIOCGWINSZ, &ws);
	while (i < pos && line[i])
	{
		if (index.co == ws.ws_col - 1 || line[i] == '\n')
		{
			index.co = 0;
			index.li++;
		}
		else
			index.co++;
		i++;
	}
	return (index);
}

/*
** get index of line by the position of cursor in terminal
*/

int					line_index(char *line, struct s_cursor cursor)
{
	struct winsize	ws;
	int				co;
	int				i;
	int				li;

	ioctl(0, TIOCGWINSZ, &ws);
	co = cursor.prompt;
	i = -1;
	li = 1;
	if (line == NULL)
		return (0);
	while (line[++i])
	{
		if (li == cursor.li && cursor.co == co)
			return (i);
		if (line[i] == '\n' || co == ws.ws_col - 1)
		{
			li++;
			co = 0;
		}
		else
			co++;
	}
	return (i);
}

/*
** place the cursor back to it's original place after editing in line
*/

void				cursor_reset(char *line, struct s_cursor cursor)
{
	struct s_cursor	last;

	last = last_cursor(line, cursor.prompt);
	if (last.co == 0 && line[ft_strlen(line) - 1] != '\n')
		last.li--;
	if (last.li > cursor.li)
		tputs(tgoto(tgetstr("UP", NULL), 0, last.li - cursor.li)
		, 1, err_putchar);
	tputs(tgoto(tgetstr("ch", NULL), 0, cursor.co), 1, err_putchar);
}

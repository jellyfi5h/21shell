/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 03:11:03 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/08 04:28:00 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

static	int	special_char(char c)
{
	if (!ft_isalnum(c))
		return (1);
	return (0);
}

/*
** navigate the cursor to the first char of the next word
*/

static	int	next_word(const char *str, int pos)
{
	while (str[pos])
	{
		if (special_char(str[pos]))
		{
			while (special_char(str[pos]))
				pos++;
			return (pos);
		}
		pos++;
	}
	return (pos);
}

/*
** navigate the cursor to the first char of the previous word
*/

static	int	previous_word(const char *str, int pos)
{
	while (pos >= 0 && str[pos])
	{
		if ((special_char(str[pos - 1]) || pos == 0)
				&& (!special_char(str[pos])))
			return (pos);
		pos--;
	}
	return (pos);
}

void		navigate_next_word(char *line, struct s_cursor *cursor)
{
	struct s_cursor	index;
	int				pos;

	pos = line_index(line, *cursor);
	if ((pos = next_word(line, pos)) <= ft_strlen(line))
	{
		index = cursor_index(line, pos, cursor->prompt);
		if (index.li - cursor->li > 0)
			tputs(tgoto(tgetstr("DO", NULL), 0, index.li - cursor->li)
			, 1, err_putchar);
		cursor->li = index.li;
		cursor->co = index.co;
	}
}

void		navigate_previous_word(char *line, struct s_cursor *cursor)
{
	struct s_cursor		index;
	int					pos;

	pos = line_index(line, *cursor);
	if ((pos = previous_word(line, pos - 1)) >= 0)
	{
		index = cursor_index(line, pos, cursor->prompt);
		if (cursor->li - index.li > 0)
			tputs(tgoto(tgetstr("UP", NULL), 0, cursor->li - index.li)
			, 1, err_putchar);
		cursor->li = index.li;
		cursor->co = index.co;
	}
}

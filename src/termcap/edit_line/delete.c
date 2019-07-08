/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:47:32 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 12:05:46 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"
#include "../../../includes/vsh.h"

/*
** delete nbr of charachters given from text
** first we delete all text after cursor position
** second rewrite the rest of line after deleting charachters
*/

void	delete_key(char **line, struct s_cursor *cursor, int nbr)
{
	int		pos;

	pos = line_index(*line, *cursor);
	while (nbr > 0 && pos > 0)
	{
		cursor_navigate_left(*line, cursor);
		delete_char(*line, pos - 1);
		nbr--;
		pos--;
	}
	tputs(tgoto(tgetstr("ch", NULL), 0, cursor->co), 1, err_putchar);
	tputs(tgetstr("cd", NULL), 1, err_putchar);
	write_line(*line, *cursor);
	cursor_reset(*line, *cursor);
}

/*
** CTRL+D delete charchters after cursor without moving cursor
** && exit from shell if line empty
*/

void	end_of_life(char **line, struct s_cursor cursor, t_env *env)
{
	int		pos;

	if (ft_strlen(*line) == 0 && env != NULL)
		exit_shell(env);
	pos = line_index(*line, cursor);
	delete_char(*line, pos);
	tputs(tgetstr("cd", NULL), 1, err_putchar);
	write_line(*line, cursor);
}

/*
** clear screen!!
*/

void	reset_screen(struct s_termcap info)
{
	tputs(tgetstr("cl", NULL), 1, err_putchar);
	ft_putstr(info.prompt);
	write_line(info.line, (struct s_cursor){info.cursor.prompt,
			1, info.cursor.prompt});
	cursor_reset(info.line, info.cursor);
}

/*
** clear all lines existed
*/

void	clear_all_lines(struct s_cursor cursor)
{
	tputs(tgoto(tgetstr("ch", NULL), 0, cursor.prompt), 1, err_putchar);
	if (cursor.li > 1)
		tputs(tgoto(tgetstr("UP", NULL), 0, cursor.li - 1), 1, err_putchar);
	tputs(tgetstr("cd", NULL), 1, err_putchar);
}

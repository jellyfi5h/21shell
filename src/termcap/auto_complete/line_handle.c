/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 21:37:52 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/12 21:43:31 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

int		nbr_line(t_file *file, int cl)
{
	int				li;
	struct winsize	ws;
	int				nbr;
	int				len;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	ws.ws_col -= 20;
	li = 1;
	len = file_len(file);
	nbr = ws.ws_col % cl;
	while (len > 0)
	{
		if (nbr >= li)
			len -= ((ws.ws_col / cl) + 1);
		else
			len -= (ws.ws_col / cl);
		li++;
	}
	return (li);
}

void	remove_lines(char *str)
{
	int li;

	li = last_cursor(str, 0).li;
	if (li > 1)
		tputs(tgoto(tgetstr("UP", NULL), 0, li - 1),
				1, err_putchar);
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, err_putchar);
	tputs(tgetstr("cd", NULL), 1, err_putchar);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_navigate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:34:03 by aboukhri          #+#    #+#             */
/*   Updated: 2019/04/27 03:42:55 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

/*
**	redisplay the line with selection mode
*/

static	void	putstr_select_mode(char *str, int begin, int end)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == begin)
			tputs("\e[46m", 1, err_putchar);
		if (i == end)
			tputs("\e[0m", 1, err_putchar);
		ft_putchar(str[i]);
		i++;
	}
	if (end == i)
		tputs("\e[0m", 1, err_putchar);
}

/*
**	select one charather to the right (rewrite the line + the slected charather)
*/

int				select_right(char *line, char **select
		, struct s_cursor *cursor, int pos)
{
	int index;
	int len;

	len = ft_strlen(line);
	index = line_index(line, *cursor);
	if (index + 1 < len)
	{
		index++;
		cursor_navigate_right(line, cursor);
		clear_all_lines(*cursor);
		if (pos >= 0)
		{
			*select = ft_strjoin(*select, (char[2]){line[index], '\0'});
			putstr_select_mode(line, index - ft_strlen(*select) + 1, index + 1);
		}
		else
		{
			delete_char(*select, ft_strlen(*select) - 1);
			putstr_select_mode(line, index, index + ft_strlen(*select));
		}
		cursor_reset(line, *cursor);
		return (1);
	}
	return (0);
}

int				select_left(char *line, char **select,
		struct s_cursor *cursor, int pos)
{
	int		index;
	int		len;

	len = ft_strlen(line);
	index = line_index(line, *cursor);
	if (index > 0)
	{
		index--;
		cursor_navigate_left(line, cursor);
		clear_all_lines(*cursor);
		if (pos <= 0)
		{
			*select = ft_strjoin((char[2]){line[index], '\0'}, *select);
			putstr_select_mode(line, index, index + ft_strlen(*select));
		}
		else
		{
			delete_char(*select, ft_strlen(*select) - 1);
			putstr_select_mode(line, index - ft_strlen(*select) + 1, index + 1);
		}
		cursor_reset(line, *cursor);
		return (-1);
	}
	return (0);
}

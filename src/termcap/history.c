/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 20:28:31 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 11:20:38 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcap.h"

static	void	read_keys(struct s_history *history, int key)
{
	int		h_len;

	h_len = ft_dbl_strlen(history->list);
	if (history->index == 0 && key != K_DOWN)
		history->index = h_len;
	if (key == K_UP && history->index > 1)
		history->index--;
	else if (key == K_DOWN)
	{
		if (history->index < h_len - 1 && history->index > 0)
			history->index++;
		else
			history->index = 0;
	}
}

static	void	insert_history(char *line, struct s_history *history)
{
	int		h_len;

	history->index = 0;
	h_len = ft_dbl_strlen(history->list);
	if (h_len == 0)
	{
		history->list = (char **)ft_memalloc(sizeof(char*) * 3);
		history->list[0] = (char*)ft_memalloc(1);
		history->list[1] = ft_strdup(line);
	}
	else
	{
		history->list = ft_realloc_double(history->list, 1);
		history->list[h_len] = ft_strdup(line);
	}
}

static	void	navigate_history(struct s_termcap *info,
				struct s_history *history, int key)
{
	if (history->index == 0)
	{
		if (history->list[history->index] != NULL)
			ft_strdel(&history->list[history->index]);
		history->list[history->index] = ft_strdup(info->line);
	}
	read_keys(history, key);
	ft_strdel(&info->line);
	clear_all_lines(info->cursor);
	info->cursor.co = info->cursor.prompt;
	info->cursor.li = 1;
	print_line(&info->line, history->list[history->index], &info->cursor);
}

void			history_keys(struct s_termcap *info, int key)
{
	if (key == 0 && info->content != NULL)
		insert_history(info->content, &info->history);
	else if (key > 0 && info->history.list != NULL)
		navigate_history(info, &info->history, key);
}

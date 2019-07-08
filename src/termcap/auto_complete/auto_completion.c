/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:38:40 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 01:19:15 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/vsh.h"
#include "../../../includes/termcap.h"

static	int			cursor_autocomplete(struct s_termcap info)
{
	int		li;
	int		last;

	last = last_cursor(info.line, info.cursor.prompt).li;
	li = info.cursor.li;
	while (li <= last)
	{
		tputs(tgetstr("do", NULL), 1, err_putchar);
		li++;
	}
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, err_putchar);
	li = display_files(info.complete);
	if (li == 0)
	{
		ft_putstr(info.prompt);
		write_line(info.line, (struct s_cursor){info.cursor.prompt,
				1, info.cursor.prompt});
		return (0);
	}
	if (li > 0)
		tputs(tgoto(tgetstr("UP", NULL), 0, li + 1), 1, err_putchar);
	tputs(tgoto(tgetstr("ch", NULL), 0, info.cursor.co), 1, err_putchar);
	return (li);
}

static	void		print_autocomplete(struct s_termcap *info, t_file ptr)
{
	char	*path;
	int		nbr_char;

	if (info->complete.path != NULL)
		path = ft_strjoin(info->complete.path, ptr.name);
	else
		path = ft_strdup(ptr.name);
	if (info->complete.len_files == 1 && ptr.type != 'd')
		path = ft_strjoinfree(path, " ");
	nbr_char = start_pos(info->line, info->cursor);
	delete_key(&info->line, &info->cursor, nbr_char);
	print_line(&info->line, path, &info->cursor);
	free(path);
}

static	void		complete_line(struct s_termcap *info, t_file **ptr)
{
	static	int		space;

	if (!(info->complete.files))
	{
		space = 1;
		info->complete.files = insert_files(info->line,
				line_index(info->line, info->cursor), info->complete);
		*ptr = info->complete.files;
		if (info->complete.files == NULL)
			return ;
		else
			info->complete.len_files = file_len(info->complete.files);
	}
	if (info->complete.files &&
		(info->complete.len_files == 1 || info->complete.check_first & 1))
		print_autocomplete(info, **ptr);
	if (info->complete.len_files > 1 && space > 0)
		space = cursor_autocomplete(*info);
}

static	void		move_next_complet(int key, struct s_termcap *info,
		t_file **pos)
{
	if (info->complete.check_first & 1)
		read_select_keys(key, info->complete, pos);
	info->complete.check_first |= 1;
	complete_line(info, pos);
}

void				auto_complete(struct s_termcap *info, char buff[5])
{
	int			key;
	t_file		*pos;

	pos = NULL;
	set_autocomplete(info);
	complete_line(info, &pos);
	if (pos != NULL)
		pos->nav = 1;
	while (info->complete.len_files > 1 && read(0, buff, 3) > 0)
	{
		key = *((int *)buff);
		if (!info->complete.stop || (key != K_DOWN && key != K_UP && key != '\t'
					&& key != K_RIGHT && key != K_LEFT))
		{
			if (key == K_RETURN || key == K_ESC)
				ft_bzero(buff, 5);
			break ;
		}
		if (key == K_DOWN || key == K_UP || key == '\t'
				|| key == K_RIGHT || key == K_LEFT)
			move_next_complet(key, info, &pos);
		ft_bzero(buff, 5);
	}
	free_autocomplete(&info->complete);
}

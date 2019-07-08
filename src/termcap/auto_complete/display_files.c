/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:45:56 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/12 21:40:32 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

static	void	display_line(t_file *file, int cl, int li)
{
	int		i;
	char	*space;

	while (file)
	{
		if (file->nav & 1)
			tputs(tgetstr("so", NULL), 0, err_putchar);
		ft_putstr(file->name);
		if (file->nav & 1)
			tputs(tgetstr("se", NULL), 0, err_putchar);
		space = str_space(cl - ft_strlen(file->name));
		ft_putstr(space);
		i = -1;
		while (file && ++i < li)
			file = file->next;
		free(space);
	}
}

static	int		read_answear(struct s_autocomplete complete,
		char *quest, int column_size, int nbrli)
{
	int		buff[2];
	int		i;

	ft_bzero(buff, 2);
	read(0, buff, 1);
	remove_lines(quest);
	if (buff[0] == 'y' || buff[0] == '\t' || buff[0] == K_RETURN)
	{
		if (column_size >= tgetnum("co"))
			put_files(complete.files);
		else
		{
			i = -1;
			while (complete.files && ++i < nbrli)
			{
				display_line(complete.files, column_size, nbrli);
				complete.files = complete.files->next;
				ft_putchar('\n');
			}
		}
		return (0);
	}
	return (-1);
}

static	int		ask_and_reply(struct s_autocomplete complete,
		int column_size, int nbrli)
{
	char	*quest;

	quest = ft_strdup("do you wish to see all ");
	quest = ft_strjoinfree(quest, ft_itoa(complete.len_files));
	quest = ft_strjoinfree(quest, " possibilities (");
	quest = ft_strjoinfree(quest, ft_itoa(nbrli));
	quest = ft_strjoinfree(quest, " lines)? ");
	ft_putstr(quest);
	if (read_answear(complete, quest, column_size, nbrli) == -1)
	{
		tputs(tgetstr("up", NULL), 1, err_putchar);
		free(quest);
		return (-1);
	}
	free(quest);
	return (0);
}

int				display_files(struct s_autocomplete complete)
{
	int				cl;
	int				nbrli;
	int				i;
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	cl = column_size(complete.files);
	if ((ws.ws_col / cl) > 1)
		nbrli = nbr_line(complete.files, cl);
	else
		nbrli = complete.len_files;
	if (nbrli >= ws.ws_row - 1)
		return (ask_and_reply(complete, cl, nbrli));
	else
	{
		i = -1;
		while (complete.files && ++i < nbrli)
		{
			display_line(complete.files, cl, nbrli);
			complete.files = complete.files->next;
			ft_putchar('\n');
		}
		return (nbrli);
	}
}

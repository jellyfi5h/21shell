/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:26:58 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/11 05:18:08 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

static	void	nav_index(int index, t_file *files, t_file **pos)
{
	(*pos)->nav = ~(*pos)->nav;
	while (files)
	{
		if (files->index == index)
		{
			*pos = files;
			(*pos)->nav = 1;
			break ;
		}
		files = files->next;
	}
}

static	void	read_right(struct s_autocomplete complete, t_file **pos)
{
	int		index;
	int		a;
	int		cl;
	int		li;

	a = 0;
	index = 0;
	cl = column_size(complete.files);
	li = nbr_line(complete.files, cl);
	if ((*pos)->index + li > complete.len_files)
	{
		a = 1;
		while (a * li < (*pos)->index)
			a++;
		a = (a - 1) * li;
		while (a < (*pos)->index)
		{
			a++;
			index++;
		}
	}
	else
		index = (*pos)->index + li;
	nav_index(index, complete.files, pos);
}

static	void	read_left(struct s_autocomplete complete, t_file **pos)
{
	int		index;
	int		a;
	int		li;

	a = 0;
	index = 0;
	li = nbr_line(complete.files, column_size(complete.files));
	if ((*pos)->index - li <= 0)
	{
		a = li;
		while (a < complete.len_files)
			a += li;
		if ((*pos)->index == li)
			index = (a <= complete.len_files) ? a : a - li;
		else
		{
			while (a > 0 && (a + (*pos)->index) > complete.len_files)
				a -= li;
			index = (a > 0) ? a + (*pos)->index : 0;
		}
	}
	else
		index = (*pos)->index - li;
	if (index > 0)
		nav_index(index, complete.files, pos);
}

void			read_updown(int key, struct s_autocomplete complete,
		t_file **pos)
{
	int		index;

	index = 0;
	if (key == K_DOWN || key == '\t')
	{
		(*pos)->nav = ~(*pos)->nav;
		(*pos) = ((*pos)->next) ? (*pos)->next : complete.files;
		(*pos)->nav = ~(*pos)->nav;
	}
	else if (key == K_UP)
	{
		index = ((*pos)->index == 1) ? complete.len_files : (*pos)->index - 1;
		nav_index(index, complete.files, pos);
	}
}

void			read_rightleft(int key, struct s_autocomplete complete,
		t_file **pos)
{
	struct winsize	ws;

	ioctl(0, TIOCGSIZE, &ws);
	if (key == K_RIGHT)
		read_right(complete, pos);
	else if (key == K_LEFT)
		read_left(complete, pos);
}

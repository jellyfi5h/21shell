/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 03:26:58 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 11:50:18 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vsh.h"
#include "../includes/termcap.h"

static	void	reset_line(struct s_termcap *info)
{
	if (info->content != NULL)
	{
		ft_strdel(&info->content);
		info->content = (char*)ft_memalloc(1);
	}
	if (info->line != NULL)
	{
		ft_strdel(&info->line);
		info->line = (char*)ft_memalloc(1);
	}
	set_info_termcap(info, get_prompt());
}

void			signal_effect(int sig, struct s_termcap *info)
{
	if (sig == SIGINT)
	{
		info->complete.stop = 0;
		if (info->line != NULL)
		{
			home_end_keys(K_END, info);
			ft_putchar('\n');
			ft_putstr(get_prompt());
		}
		reset_line(info);
		tputs(tgetstr("cd", NULL), 1, err_putchar);
	}
}

void			handler(int sig)
{
	if (sig == SIGINT)
		set_line(sig, NULL);
}

void			signals_handling(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}

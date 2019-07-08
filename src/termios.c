/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:48:18 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 01:18:13 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/termcap.h"

/*
**	disable canonical & ECHO modes
*/

void	disable_term(void)
{
	int				fd;
	struct termios	term;

	fd = open(ttyname(0), O_RDWR);
	if (isatty(fd))
	{
		tcgetattr(fd, &term);
		term.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(fd, TCSANOW, &term);
	}
	close(fd);
}

void	enable_term(void)
{
	int				fd;
	struct termios	term;

	fd = open(ttyname(0), O_RDWR);
	if (isatty(fd))
	{
		tcgetattr(fd, &term);
		term.c_lflag |= ICANON;
		term.c_lflag |= ECHO;
		tcsetattr(fd, TCSANOW, &term);
	}
	close(fd);
}

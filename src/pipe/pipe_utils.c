/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfetoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:47:30 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/19 07:14:25 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"

pid_t		*childs_creation(int len)
{
	pid_t	*child;
	int		i;

	child = (pid_t *)malloc(sizeof(pid_t) * len);
	i = 0;
	while (i < len)
		child[i++] = 0;
	i = 0;
	while (i < len - 1)
	{
		if (i == 0)
			child[i] = fork();
		if (child[i] > 0)
			child[i + 1] = fork();
		i++;
	}
	return (child);
}

void		pipe_creation(int len, int *fd)
{
	int		i;

	i = 0;
	while (i < len - 1)
		pipe(fd + (2 * i++));
}

void		pipe_close_fd(int len, int *fd)
{
	int		i;

	i = 0;
	while (i < (len - 1) * 2)
		close(fd[i++]);
}

void		pipe_duplication(int *fd, int a, int b, int c)
{
	close(fd[a]);
	dup2(fd[b], c);
	close(fd[c]);
}

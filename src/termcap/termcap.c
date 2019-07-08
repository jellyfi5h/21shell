/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 12:21:38 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 13:21:28 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vsh.h"
#include "../../includes/builtins.h"

char	*get_prompt(void)
{
	char	*path;
	char	*dir;
	char	*prompt;

	path = getpwd();
	dir = ft_strdup("\033[1;36m");
	if (ft_chrlen(path, '/') == 1)
		dir = ft_strjoinfree(dir, "/");
	else
		dir = ft_strjoinfree(dir, ft_strrchr(path, '/'));
	dir = ft_strjoinfree(dir, "\033[0m");
	prompt = ft_strjoinfree(dir, "\033[1;31m ✗ \033[0m");
	free(path);
	return (prompt);
}

void	set_info_termcap(struct s_termcap *info, char *prompt)
{
	int	len;

	info->prompt = ft_strdup(prompt);
	len = ft_strlen(info->prompt) - 24;
	info->cursor = (struct s_cursor){len, 1, len};
	free(prompt);
}

int		get_col_pos(void)
{
	char	buf[30];
	int		i;
	int		pow;
	int		ch;

	ft_bzero(buf, 30);
	write(1, "\033[6n", 4);
	i = 0;
	ch = 0;
	while (ch != 'R')
	{
		(read(0, &ch, 1) > 0) && (buf[i] = ch);
		i++;
	}
	if (i < 2)
		return (-1);
	i -= 1;
	pow = 1;
	ch = 0;
	while (buf[--i] != ';')
	{
		ch = ch + (buf[i] - '0') * pow;
		pow *= 10;
	}
	return (ch);
}

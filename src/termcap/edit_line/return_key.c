/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:06:53 by aboukhri          #+#    #+#             */
/*   Updated: 2019/07/08 15:56:29 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

void	return_line(struct s_termcap *info)
{
	char	*trim;

	trim = ft_strtrim(info->line);
	home_end_keys(K_END, info);
	info->content = ft_strjoinfree(info->content, trim);
	info->cursor = (struct s_cursor){info->cursor.prompt, 1,
		info->cursor.prompt};
	free(trim);
}

int		return_key(struct s_termcap *info)
{
	int		prompt;

	return_line(info);
	if (info->line != NULL)
		ft_strdel(&info->line);
	prompt = read_quote(info->content);
	if (!prompt)
	{
		if (ft_strlen(info->content))
			history_keys(info, 0);
		return (1);
	}
	info->cursor.prompt = prompt;
	info->cursor.co = prompt;
	info->line = ft_memalloc(1);
	info->content = ft_strjoinfree(info->content, "\n");
	return (0);
}

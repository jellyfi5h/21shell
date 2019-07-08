/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:24:44 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/18 08:10:24 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

int		get_word_index(char *line, int pos)
{
	int		cpt;
	int		index;

	cpt = 0;
	index = 0;
	while (cpt <= pos && line[cpt])
	{
		if ((line[cpt] == ' ' || line[cpt] == '\n') &&
				(line[cpt + 1] != ' ' && line[cpt + 1] != '\n'))
			index++;
		cpt++;
	}
	return (index);
}

char	*str_word_index(char *line, int pos)
{
	int		bg;
	int		end;

	bg = pos - 1;
	end = pos;
	while (bg >= 0 && line[bg] != ' ' && line[bg] != '\t' && line[bg] != '\n')
		bg--;
	while (line[end] && line[end] != ' ' &&
			line[end] != '\t' && line[end] != '\n')
		end++;
	return (ft_strsub(line, bg + 1, end));
}

char	*str_space(int size)
{
	char	*str;
	int		i;
	int		bl;

	str = (char*)ft_memalloc(size + 1);
	i = -1;
	bl = 0;
	while (++i < size)
		str[i] = ' ';
	return (str);
}

int		start_pos(char *line, struct s_cursor cursor)
{
	int		pos;
	int		nbr;
	char	*str;

	nbr = 0;
	pos = line_index(line, cursor);
	str = ft_strsub(line, 0, pos);
	while (pos >= 0)
	{
		if (str[pos] == '\n' || (str[pos] == ' ' && (pos > 0
						&& str[pos - 1] != '\\')))
			break ;
		nbr++;
		pos--;
	}
	free(str);
	return (nbr - 1);
}

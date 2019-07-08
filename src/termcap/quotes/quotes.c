/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:59:16 by aboukhri          #+#    #+#             */
/*   Updated: 2019/07/08 15:51:31 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

/*
** check if line has quotes
*/

static	int	quotes(char *line)
{
	int		i;
	char	c;
	int		bl;

	i = -1;
	bl = 1;
	c = 0;
	while (line[++i])
	{
		if ((line[i] == '"' || line[i] == '\'') && bl)
		{
			bl = 0;
			c = line[i];
		}
		else if (line[i] == c)
			bl = 1;
	}
	if (!bl)
		return (c);
	return (-1);
}

/*
** after pressing enter this function checks if their was any quotes
** and return length of prompt
*/

int			read_quote(char *line)
{
	int		c;

	if (*line && (c = quotes(line)) > 0)
	{
		ft_putchar('\n');
		if (c == '"')
		{
			ft_putchar('d');
			c = 7;
		}
		else
			c = 6;
		ft_putstr("quote>");
		return (c);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 06:54:49 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/20 02:15:16 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	quotes(char c, char quote)
{
	if (c == '"' || c == '\'')
	{
		if (quote == 0)
			quote = c;
		else if (quote == c)
			quote = 0;
	}
	return (quote);
}

static	int		len_split(char *str, char c)
{
	int		i;
	int		cpt;
	char	q;

	i = 0;
	cpt = 0;
	q = 0;
	while (str[i] != '\0')
	{
		q = quotes(str[i], q);
		if (q == 0)
		{
			if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
				cpt++;
		}
		i++;
	}
	return (cpt);
}

static	void	fill_split(char *str, char **split, char c)
{
	int		i;
	int		j;
	int		len;
	char	q;

	q = 0;
	i = -1;
	j = 0;
	len = 0;
	while (str[++i])
	{
		q = quotes(str[i], q);
		if (str[i] != c || q != 0)
		{
			len++;
			if ((str[i + 1] == c && q == 0) || str[i + 1] == '\0')
			{
				split[j] = (char*)malloc(len + 1);
				j++;
				len = 0;
			}
		}
	}
}

static	void	complete_split(char *str, char **split, char c)
{
	int		i;
	int		j;
	int		cpt;
	char	q;

	i = -1;
	j = 0;
	cpt = 0;
	q = 0;
	while (str[++i])
	{
		q = quotes(str[i], q);
		if (str[i] != c || q != 0)
		{
			split[cpt][j] = str[i];
			j++;
			if ((str[i + 1] == c && q == 0) || str[i + 1] == '\0')
			{
				split[cpt][j] = '\0';
				cpt++;
				j = 0;
			}
		}
	}
	split[cpt] = NULL;
}

char			**ft_strsplit_quote(char *str, char c)
{
	int		size;
	char	**split;

	if (str == NULL)
		return (NULL);
	if ((size = len_split(str, c)) == 0)
		return (NULL);
	split = (char**)malloc(sizeof(split) * (size + 1));
	if (split == NULL)
		return (NULL);
	fill_split(str, split, c);
	complete_split(str, split, c);
	return (split);
}

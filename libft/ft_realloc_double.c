/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_double.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 00:12:34 by mfetoui           #+#    #+#             */
/*   Updated: 2019/05/17 06:09:11 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_cpy_content(char **s1, char **s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != NULL)
	{
		j = 0;
		while (s1[i][j] != '\0')
		{
			s2[i][j] = s1[i][j];
			j++;
		}
		s2[i][j] = '\0';
		i++;
	}
}

char		**ft_realloc_double(char **s1, size_t size)
{
	char			**s2;
	int				string;
	int				i;
	int				j;

	i = 0;
	j = 0;
	string = 0;
	while (s1[string] != NULL)
		string++;
	s2 = (char **)malloc(sizeof(char *) * (string + 1 + size));
	s2[string + size] = NULL;
	while (s1[i] != NULL)
	{
		j = 0;
		while (s1[i][j] != '\0')
			j++;
		s2[i] = (char *)malloc(sizeof(char ) * (j + 1));
		ft_bzero(s2[i], j + 1);
		i++;
	}
	ft_cpy_content(s1, s2);
	ft_dbl_strdel(s1);
	return (s2);
}

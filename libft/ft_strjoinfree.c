/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 03:49:47 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/16 02:01:33 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	int		i;
	char	*str;
	int		j;

	if (s1 != NULL && s2 != NULL)
	{
		str = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i] != '\0')
			str[i] = s1[i];
		j = i;
		i = -1;
		while (s2[++i] != '\0')
		{
			str[j] = s2[i];
			j++;
		}
		ft_strdel(&s1);
		return (str);
	}
	return (NULL);
}

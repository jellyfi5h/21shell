/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:47:18 by aboukhri          #+#    #+#             */
/*   Updated: 2019/04/16 19:57:36 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
		return (str);
	}
	return (NULL);
}

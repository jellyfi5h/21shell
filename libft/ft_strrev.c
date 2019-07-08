/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:06:02 by aboukhri          #+#    #+#             */
/*   Updated: 2019/01/26 23:02:09 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	if (str == NULL)
		return (NULL);
	i = ft_strlen(str);
	j = 0;
	while (j < --i)
	{
		c = str[j];
		str[j] = str[i];
		str[i] = c;
		j++;
	}
	return (str);
}

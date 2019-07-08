/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 23:42:33 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/13 03:36:46 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*str;

	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL || size > SIZEMAX)
		return (NULL);
	i = -1;
	while (++i < (int)size)
		str[i] = 0;
	return (str);
}

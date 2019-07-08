/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:07:52 by aboukhri          #+#    #+#             */
/*   Updated: 2019/01/23 12:43:31 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*field_width(int count, char c)
{
	int		i;
	char	*str;

	str = (char*)ft_memalloc(count + 1);
	i = -1;
	while (++i < count)
		str[i] = c;
	return (str);
}

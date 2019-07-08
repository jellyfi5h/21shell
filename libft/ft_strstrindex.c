/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 03:50:37 by aboukhri          #+#    #+#             */
/*   Updated: 2019/02/02 03:50:43 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstrindex(const char *dst, const char *src)
{
	int		i;
	int		j;
	int		ri;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		if (src[j] == dst[i])
		{
			ri = i;
			while (src[j] == dst[ri])
			{
				ri++;
				j++;
				if (src[j] == '\0')
					return (i);
			}
			j = 0;
		}
		i++;
	}
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:35:25 by aboukhri          #+#    #+#             */
/*   Updated: 2019/01/27 17:42:52 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dst, const char *src)
{
	int		i;
	int		j;
	int		ri;

	i = 0;
	j = 0;
	if (ft_strlen(src) == 0)
		return (char*)dst;
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
					return (char*)dst + i;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

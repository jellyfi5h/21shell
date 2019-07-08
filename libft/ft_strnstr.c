/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:44:36 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/08 19:26:00 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	i;
	int		j;
	size_t	ri;

	i = 0;
	j = 0;
	if (ft_strlen(src) == 0)
		return (char*)dst;
	while (dst[i] != '\0' && i < n)
	{
		if (src[j] == dst[i])
		{
			ri = i;
			while (src[j] == dst[ri])
			{
				ri++;
				j++;
				if (src[j] == '\0' && ri <= n)
					return (char*)dst + i;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:17:50 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/08 19:44:09 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t			j;
	char			*a;

	j = 0;
	a = dest;
	while (*src && j < n)
	{
		*dest = *src;
		dest++;
		src++;
		j++;
	}
	while (j < n)
	{
		*dest = '\0';
		dest++;
		j++;
	}
	return (a);
}

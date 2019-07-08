/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:20:56 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/08 19:54:22 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned	char	*d;
	unsigned	char	*s;
	unsigned	char	z;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	i = 0;
	z = (unsigned char)c;
	while (i < n)
	{
		if ((*d = s[i]) == z)
		{
			d++;
			return (d);
		}
		d++;
		i++;
	}
	return (NULL);
}

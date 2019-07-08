/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:05:16 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/17 02:24:23 by mfetoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned	char	*p;
	size_t				i;

	i = 0;
	p = (unsigned char*)s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:17:28 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/11 01:19:22 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned	char			tmp[n];
	unsigned	char			*d;
	unsigned	const	char	*s;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	ft_memcpy(tmp, s, n);
	ft_memcpy(d, tmp, n);
	return (dest);
}

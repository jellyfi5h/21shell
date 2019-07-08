/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 18:06:47 by aboukhri          #+#    #+#             */
/*   Updated: 2019/02/02 18:07:12 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_remalloc(char *str, size_t size)
{
	ft_strdel(&str);
	if (size > 0)
		str = (char*)ft_memalloc(size);
	return (str);
}

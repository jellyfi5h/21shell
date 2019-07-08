/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:06:40 by aboukhri          #+#    #+#             */
/*   Updated: 2018/12/10 03:07:03 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrjoin(char *s, char c)
{
	int		i;
	char	*str;

	str = (char*)ft_memalloc(ft_strlen(s) + 2);
	i = -1;
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = c;
	return (str);
}

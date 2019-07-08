/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 03:07:14 by aboukhri          #+#    #+#             */
/*   Updated: 2019/01/31 06:30:12 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrlen(const char *str, char c)
{
	int		i;
	int		len;

	len = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			len++;
	}
	return (len);
}

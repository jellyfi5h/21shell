/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:28:37 by aboukhri          #+#    #+#             */
/*   Updated: 2018/11/17 21:43:20 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		get_index(const char *str)
{
	int		i;
	int		cpt;

	i = -1;
	cpt = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			cpt++;
		else if (str[i] >= '0' && str[i] <= '9')
			return (i);
		else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' &&
				str[i] != '\v' && str[i] != '\r' &&
				str[i] != '\f')
			return (-1);
		else if (cpt > 0)
			return (-1);
		if (cpt > 1)
			return (-1);
	}
	return (-1);
}

long	int		ft_atoi(const char *str)
{
	int				i;
	long	int		res;
	int				neg;

	i = get_index(str);
	res = 0;
	if (i < 0)
		return (0);
	neg = (i > 0 && str[i - 1] == '-') ? -1 : 1;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (res * neg);
		else
		{
			res *= 10;
			res += str[i] - '0';
		}
		i++;
	}
	return (res * neg);
}

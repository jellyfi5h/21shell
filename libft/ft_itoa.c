/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:06:02 by aboukhri          #+#    #+#             */
/*   Updated: 2018/11/17 21:41:41 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*sub_itoi(long long int n, char *str, long long int fac)
{
	int					i;
	char				c;
	int					j;
	long	long	int	nbr;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		str[i] = '-';
		i++;
	}
	while (fac > 0)
	{
		j = nbr / fac;
		c = j + '0';
		str[i] = c;
		nbr = nbr - (j * fac);
		fac /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(long long int n)
{
	int					i;
	long	long	int	nbr;
	char				*str;
	long long	int		fac;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		i++;
		nbr *= -1;
		i++;
	}
	else if (n == 0)
		i = 1;
	fac = 1;
	while ((nbr / fac) >= 10)
	{
		fac *= 10;
		i++;
	}
	str = (char*)malloc(sizeof(*str) * (i + 2));
	if (str == NULL)
		return (NULL);
	return (sub_itoi(n, str, fac));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:14:03 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/04 15:00:16 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	int	nbr;
	int			fac;
	char		c;
	long	int	j;

	nbr = n;
	fac = 1;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	while ((nbr / fac) >= 10)
	{
		fac *= 10;
	}
	while (fac > 0)
	{
		j = nbr / fac;
		c = j + '0';
		ft_putchar(c);
		nbr = nbr - (j * fac);
		fac /= 10;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:59:49 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/04 15:04:42 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
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
		ft_putchar_fd('-', fd);
	}
	while ((nbr / fac) >= 10)
	{
		fac *= 10;
	}
	while (fac > 0)
	{
		j = nbr / fac;
		c = j + '0';
		ft_putchar_fd(c, fd);
		nbr = nbr - (j * fac);
		fac /= 10;
	}
}

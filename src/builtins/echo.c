/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:21:24 by mfetoui           #+#    #+#             */
/*   Updated: 2019/04/27 02:03:30 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"
#include "../../includes/termcap.h"

static	void	echo_flag(int n, int argc)
{
	if (n == 1 && argc > 2)
	{
		tputs(tgetstr("so", NULL), 0, err_putchar);
		ft_putchar('%');
		tputs(tgetstr("se", NULL), 0, err_putchar);
	}
	if (n == 0 || argc > 2)
		ft_putchar('\n');
}

void			ft_echo(char **argv)
{
	int		n;
	int		i;
	int		argc;

	n = 0;
	argc = ft_dbl_strlen(argv);
	if (argc > 1)
	{
		i = 0;
		if (ft_strequ(argv[1], "-n"))
		{
			n = 1;
			i++;
		}
		while (argv[++i])
		{
			ft_putstr(argv[i]);
			(argv[i + 1]) && (write(1, " ", 2));
		}
	}
	echo_flag(n, argc);
}

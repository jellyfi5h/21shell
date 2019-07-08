/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_select.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:19:03 by aboukhri          #+#    #+#             */
/*   Updated: 2019/04/27 03:43:24 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"

int		is_column(int co, int li, int cl, int len)
{
	int		nb;

	nb = co / cl;
	if ((len % li) == 0)
		nb -= (len / li);
	else
		nb -= (len / li) + 1;
	if (nb >= 0)
		return (1);
	else
		return (0);
}

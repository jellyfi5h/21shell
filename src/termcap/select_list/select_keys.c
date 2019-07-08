/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <aboukhri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:18:02 by aboukhri          #+#    #+#             */
/*   Updated: 2019/05/19 01:08:17 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/termcap.h"
#include "../../../includes/vsh.h"

void	read_select_keys(int k, struct s_autocomplete complete, t_file **pos)
{
	if (k == K_DOWN || k == K_UP || k == '\t')
		read_updown(k, complete, pos);
	else if (k == K_RIGHT || k == K_LEFT)
		read_rightleft(k, complete, pos);
}

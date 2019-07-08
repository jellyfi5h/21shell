/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:16:06 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/11 01:16:07 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcat(t_list *dest, t_list *src)
{
	t_list	*p;

	p = dest;
	while (p->next)
		p = p->next;
	p->next = src;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:41:39 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/10 22:27:06 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst != NULL)
	{
		while (*alst)
		{
			tmp = alst[0]->next;
			del(alst[0]->content, alst[0]->content_size);
			free(*alst);
			*alst = tmp;
		}
		alst = NULL;
	}
}

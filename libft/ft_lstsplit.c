/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:47:42 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/11 01:17:47 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lstsplit(t_list *lst)
{
	t_list	*p;
	t_list	**split;
	int		size;

	p = lst;
	size = 0;
	while (p)
	{
		size++;
		p = p->next;
	}
	split = (t_list**)malloc(sizeof(*split) * (size + 1));
	size = 0;
	while (lst)
	{
		split[size] = ft_lstnew(lst->content, lst->content_size);
		size++;
		lst = lst->next;
	}
	split[size] = NULL;
	return (split);
}

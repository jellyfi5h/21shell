/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 00:45:14 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/11 01:11:07 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsearch(t_list *lst, const void *content)
{
	while (lst)
	{
		if (ft_memcmp(lst->content, content, lst->content_size) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

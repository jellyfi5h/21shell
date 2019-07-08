/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:32:45 by aboukhri          #+#    #+#             */
/*   Updated: 2018/10/10 19:21:30 by aboukhri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	tmp = ft_lstnew(f(lst)->content, f(lst)->content_size);
	current = tmp;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		current = current->next;
		lst = lst->next;
	}
	return (tmp);
}

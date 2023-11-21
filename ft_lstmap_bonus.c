/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <mrezki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:13:32 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/19 00:31:25 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_bonus(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*foo;

	if (!lst || !f)
		return (NULL);
	list = NULL;
	while (lst)
	{
		foo = ft_lstnew_bonus(f(lst->content));
		if (!foo)
		{
			ft_lstclear_bonus(&list, del);
			return (NULL);
		}
		ft_lstadd_back_bonus(&list, foo);
		lst = lst->next;
	}
	return (list);
}

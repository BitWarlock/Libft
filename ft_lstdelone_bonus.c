/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 04:23:09 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/19 00:31:45 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone_bonus(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del((lst)->content);
	free(lst);
	lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 02:49:00 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/23 22:14:09 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
//
// int main(void)
// {
// 	t_list	*head;
// 	t_list	*sec;
// 	t_list	*thrd;
//
// 	head = (t_list *)malloc(sizeof(t_list));
// 	sec = (t_list *)malloc(sizeof(t_list));
// 	thrd = (t_list *)malloc(sizeof(t_list));
// 	head->content = "123";
// 	sec->content = "456";
// 	thrd->content = "789";
// 	head->next = sec;
// 	sec->next = thrd;
// 	thrd->next = NULL;
//
// 	printf("%d\n", ft_lstsize(head));
//
// 	return EXIT_SUCCESS;
// }

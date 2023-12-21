/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:25:01 by mrezki            #+#    #+#             */
/*   Updated: 2023/12/20 16:55:11 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	while (++i < n)
		*((char *)dst + i) = *((char *)src + i);
	return (dst);
}
//
// int main(void)
// {
// 	char	dst[] = "abcdef";
// 	ft_memcpy(dst + 2, dst, 6);
// 	printf("%s\n", dst);
//
// 	return EXIT_SUCCESS;
// }

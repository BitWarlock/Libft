/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:25:01 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/06 19:09:11 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	i = -1;
	pdst = (char *)dst;
	psrc = (char *)src;
	if (!pdst && !psrc)
		return (NULL);
	while (++i < n)
		*(pdst + i) = *(psrc + i);
	return (dst);
}

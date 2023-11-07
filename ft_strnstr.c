/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:47:21 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/07 05:59:44 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len2;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	len2 = ft_strlen(needle);
	while (haystack[i] && (i + len2) <= len)
	{
		if (ft_strncmp((haystack + i), needle, len2))
			return ((char *)(haystack + 1));
		i++;
	}
	return (NULL);
}

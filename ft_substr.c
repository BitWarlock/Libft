/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:54:32 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/08 09:15:02 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
// #include <stddef.h>
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

char	*alloc(char const *s, size_t len)
{
	char	*ptr;
	size_t	i;

	if (len == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	else if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (s == NULL || start >= ft_strlen(s))
		return (NULL);
	return (alloc(s + start, len));
}
//
// int main(void)
// {
// 	printf("%s\n", ft_substr("", 0, 0));
//
// 	return EXIT_SUCCESS;
// }

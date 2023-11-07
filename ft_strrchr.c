/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:04:31 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/07 05:04:33 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = NULL;
	c = (unsigned char)c;
	while (*str)
	{
		if ((unsigned char)*str == c)
			s = (char *)str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (s);
}

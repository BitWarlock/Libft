/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:52:09 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/19 03:56:57 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_new_token(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

static int	ft_count_tokens(char const *s, char c)
{
	int	i;
	int	tokens;
	int	state;

	if (!s)
		return (0);
	state = 0;
	tokens = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			++tokens;
		}
		i++;
	}
	return (tokens);
}

static int	ft_token_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char	**free_all(char **tokens, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(tokens[i]);
	free(tokens);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		tok;
	int		j;
	int		k;
	char	**tokens;

	tokens = (char **)malloc(sizeof(char *) * (ft_count_tokens(s, c) + 1));
	if (!tokens)
		return (NULL);
	tok = -1;
	j = 0;
	while (++tok < ft_count_tokens(s, c))
	{
		k = 0;
		tokens[tok] = ft_new_token(ft_token_len(&s[j], c));
		if (!(tokens[tok]))
			return (free_all(tokens, tok));
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tokens[tok][k++] = s[j++];
		tokens[tok][k] = '\0';
	}
	tokens[tok] = NULL;
	return (tokens);
}

//
//
// int main(void)
// {
//     char	**tokens;
//     tokens = ft_split("--229-abc----229a2ac0-846b-11ee-b0f1-6798e89--", '-');
//
// 	int	i = 0;
//     for (i = 0; tokens[i] != NULL; i++)
//     {
//         printf("%s\n", tokens[i]);
// 		free(tokens[i]);
//     }
//
//     return EXIT_SUCCESS;
// }

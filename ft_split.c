/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrezki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:52:09 by mrezki            #+#    #+#             */
/*   Updated: 2023/11/16 18:37:53 by mrezki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*new_token(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = ft_calloc(sizeof(*ptr), (size + 1));
	if (!(ptr))
		return (NULL);
	return (ptr);
}

static size_t	count_tokens(const char *str, char c)
{
	size_t	i;
	size_t	tokens;

	i = 0;
	tokens = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			tokens++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (tokens);
}

static size_t	wordlen(const char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static void	*free_tokens(char **tokens, size_t len)
{
	while (len--)
		free(tokens[len]);
	free(tokens);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**tokens;
	size_t	i;
	size_t	i2;
	size_t	i3;

	tokens = (char **)malloc(sizeof(char *) * (count_tokens(s, c) + 1));
	if (s == NULL || !(tokens))
		return (NULL);
	i = -1;
	i2 = 0;
	while (++i < count_tokens(s, c))
	{
		i3 = 0;
		tokens[i] = new_token(wordlen(s + i2, c));
		if (!(tokens[i]))
			return (free_tokens(tokens, i));
		while (s[i2] == c)
			i2++;
		while (s[i2] != c && s[i2])
			tokens[i][i3++] = s[i2++];
		tokens[i][i3] = '\0';
	}
	tokens[i] = NULL;
	return (tokens);
}
//
//
// int main(void)
// {
//     char	**words;
//     words = ft_split("--229-abc----229a2ac0-846b-11ee-b0f1-6798e89--", '-');
//
// 	int	i = 0;
//     for (i = 0; words[i] != NULL; i++)
//     {
//         printf("%s\n", words[i]);
// 		free(words[i]);
//     }
//
//     return EXIT_SUCCESS;
// }
//
// static int	count_words(char const *s, char c)
// {
// 	int	i;
// 	int	words;
// 	int	state;
//
// 	state = 0;
// 	words = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == c)
// 			state = 0;
// 		else if (state == 0)
// 		{
// 			state = 1;
// 			++words;
// 		}
// 		i++;
// 	}
// 	return (words);
// }
//
// static void	*free_w(char **words, int len)
// {
// 	int	i;
//
// 	i = -1;
// 	while (++i < len)
// 		free(words[i]);
// 	free(words);
// 	return (NULL);
// }
//
// static char	*fill(char *s, int start, int end)
// {
// 	int	i;
// 	char	*ptr;
//
// 	i = 0;
// 	ptr = ft_calloc(sizeof(char), (end - start + 2));
// 	if (!ptr)
// 		return (NULL);
// 	ft_memcpy(ptr, s + start, (end - start + 1));
// 	return (ptr);
// }
//
// char	**ft_split(char const *s, char c)
// {
// 	char	**words;
// 	int	start;
// 	int	end;
// 	int	w;
//
// 	start = 0;
// 	w = 0;
// 	end = 0;
// 	words = ft_calloc(sizeof(char *), count_words(s, c) + 1);
// 	if (!words)
// 		return (NULL);
// 	while (s[end])
// 	{
// 		if (s[end] != c && start < 0)
// 			start = end;
// 		else if ((s[end] == c || s[end]) && start >= 0)
// 		{
// 			words[w] = fill((char *)s, start, end - 1);
// 			if (!words[w])
// 				return (free_w(words, w));
// 			w++;
// 			start = -1;
// 		}
// 		end++;
// 	}
// 	return (words);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:06:22 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/17 19:50:05 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

size_t	ft_words_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		free (str[i]);
		i++;
	}
	free (str);
}

char	**ft_do_split(char const *s, char c, char **str, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		str[i] = ft_substr(s, j, (ft_words_len (&s[j], c)));
		if (!str[i])
			return (ft_free(str), NULL);
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	str = ft_do_split(s, c, str, words);
	return (str);
}
/*
int	main()
{
	char **f = ft_split(" hola mundo 42 !", 'o');
	if (f)
	{
		for (int i = 0; f[i] != NULL; i++)
		{
    		printf("%s\n", f[i]);
		}
	}
    return (0);
}*/

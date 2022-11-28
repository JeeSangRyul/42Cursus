/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:03:00 by sji               #+#    #+#             */
/*   Updated: 2022/07/19 18:43:09 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_c(char str_c, char c)
{
	if (str_c == c)
		return (1);
	if (str_c == '\0')
		return (1);
	return (0);
}

void	ft_strcpy(char *dest, char const *s, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

void	all_free(char **result, size_t word)
{
	size_t	i;

	i = 0;
	while (i < word)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	fill_result_array(char **result, char const *s, char c)
{
	size_t	j;
	size_t	word;
	size_t	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (check_c(s[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (check_c(s[i + j], c) == 0)
				j++;
			result[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (result[word] == 0)
				all_free(result, word);
			ft_strcpy(result[word], s + i, j);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (check_c(s[i + 1], c) == 1
			&& check_c(s[i], c) == 0)
			word++;
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (!result)
		return (NULL);
	result[word] = 0;
	if (word == 0)
		return (result);
	fill_result_array(result, s, c);
	return (result);
}

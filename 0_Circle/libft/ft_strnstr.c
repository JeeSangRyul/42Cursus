/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:03:37 by sji               #+#    #+#             */
/*   Updated: 2022/07/19 18:54:02 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_str(const char *str, const char *to_find, size_t i, size_t len)
{
	const char	*a;
	const char	*b;
	size_t		j;

	a = str;
	b = to_find;
	j = 0;
	if (*a == *b && i < len)
	{
		while (*(a + j) == *(b + j) && *(b + j) != '\0' && i + j < len)
			j++;
		if (*(b + j) == '\0')
			return ((char *)str);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	const char	*s;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		s = find_str(haystack, needle, i, len);
		if (s != NULL)
			return ((char *)s);
		haystack++;
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:03:21 by sji               #+#    #+#             */
/*   Updated: 2022/07/13 21:55:40 by sji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = ft_strlen(dst);
	b = ft_strlen(src);
	c = 0;
	if (a > dstsize)
		return (b + dstsize);
	while (src[c] != '\0' && a + c + 1 < dstsize)
	{
		dst[a + c] = src[c];
		c++;
	}
	dst[a + c] = '\0';
	return (a + b);
}

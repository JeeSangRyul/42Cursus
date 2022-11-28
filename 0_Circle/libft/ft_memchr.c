/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:02:20 by sji               #+#    #+#             */
/*   Updated: 2022/07/13 21:42:06 by sji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			index;

	index = 0;
	str = (unsigned char *)s;
	while (index < n)
	{
		if (str[index] == (unsigned char)c)
			return ((void *)&str[index]);
		index++;
	}
	return (0);
}

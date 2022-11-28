/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:02:28 by sji               #+#    #+#             */
/*   Updated: 2022/07/13 21:57:11 by sji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;
	size_t		i;

	dest_ptr = (char *)dst;
	src_ptr = (char *)src;
	i = 0;
	if (dest_ptr == src_ptr)
		return (dst);
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

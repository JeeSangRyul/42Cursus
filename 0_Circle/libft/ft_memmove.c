/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:02:32 by sji               #+#    #+#             */
/*   Updated: 2022/07/13 21:56:49 by sji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if ((dst_ptr == src_ptr) || len == 0)
		return (dst);
	i = -1;
	if (dst_ptr < src_ptr)
	{
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	}
	else
	{
		while (++i < len)
			dst_ptr[len - i - 1] = src_ptr[len - i - 1];
	}
	return (dst);
}

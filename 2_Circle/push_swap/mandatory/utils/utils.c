/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:32:50 by sji               #+#    #+#             */
/*   Updated: 2023/01/10 22:29:39 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static	void	ft_isdigit(const char *str, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			throw_error(stacks);
		i++;
	}
}

long long	ft_atoi(const char *str, t_stacks *stacks)
{
	size_t			i;
	long long		sign;
	long long		num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (!str[i])
		throw_error(stacks);
	ft_isdigit(&str[i], stacks);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		++i;
	}
	return (sign * num);
}

static	void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, 0, n));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && (count * size) / size != count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

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

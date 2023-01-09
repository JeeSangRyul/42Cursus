/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:32:50 by sji               #+#    #+#             */
/*   Updated: 2023/01/08 20:56:03 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	write(1, &s[i], ft_strlen(s));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static	void	ft_isdigit(const char *str, t_stacks *stacks)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			free_all_stack(stacks);
		i++;
	}
}

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
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
		free_all_stack(stacks);
	ft_isdigit(&str[i], stacks);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		++i;
	}
	return (sign * num);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
		str[i++] = c;
	return (b);
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
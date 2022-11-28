/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:55:50 by sji               #+#    #+#             */
/*   Updated: 2022/09/07 15:52:51 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_ptr(unsigned long long ptr)
{
	char	*base;
	char	stack[17];
	int		i;
	int		res;

	if (ptr == 0)
		return (print_str("0x0"));
	i = 0;
	base = "0123456789abcdef";
	write(1, "0x", 2);
	while (ptr)
	{
		stack[i] = base[ptr % 16];
		ptr /= 16;
		i++;
	}
	res = i--;
	while (i > -1)
	{
		write(1, &stack[i], 1);
		i--;
	}
	return (res + 2);
}

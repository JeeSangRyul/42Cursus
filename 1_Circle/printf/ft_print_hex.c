/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:52:13 by sji               #+#    #+#             */
/*   Updated: 2022/09/07 16:05:23 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_unsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static char	*put_hex(unsigned int n, const char format)
{
	char	*result;
	char	*base;
	int		len;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = hex_unsigned(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		result[len--] = base[n % 16];
		n /= 16;
	}
	return (result);
}

int	print_hex(unsigned int c, const char format)
{
	char	*res;
	int		len;

	res = put_hex(c, format);
	len = print_str(res);
	free(res);
	return (len);
}

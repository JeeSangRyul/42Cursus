/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:41:09 by sji               #+#    #+#             */
/*   Updated: 2022/09/07 15:56:47 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char c, va_list ap)
{
	int	printed_len;

	printed_len = 0;
	if (c == 'c')
		printed_len += print_char((char)va_arg(ap, int));
	else if (c == '%')
		printed_len += print_char('%');
	else if (c == 's')
		printed_len += print_str(va_arg(ap, char *));
	else if (c == 'p')
		printed_len += print_ptr(va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		printed_len += print_nbr(va_arg(ap, int));
	else if (c == 'u')
		printed_len += print_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		printed_len += print_hex(va_arg(ap, unsigned int), c);
	return (printed_len);
}

int	ft_printf(const char *format, ...)
{
	int		printed_len;
	int		i;
	va_list	ap;

	printed_len = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_len += check_type(format[i], ap);
		}
		else
			printed_len += print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (printed_len);
}

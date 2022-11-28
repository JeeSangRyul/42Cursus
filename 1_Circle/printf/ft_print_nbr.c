/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:55:19 by sji               #+#    #+#             */
/*   Updated: 2022/09/07 16:05:41 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int c)
{
	char	*res;
	int		len;

	res = ft_itoa(c);
	len = print_str(res);
	free(res);
	return (len);
}

int	print_unsigned(unsigned int c)
{
	char	*res;
	int		len;

	res = ft_uitoa(c);
	len = print_str(res);
	free(res);
	return (len);
}

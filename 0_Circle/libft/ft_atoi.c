/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:01:56 by sji               #+#    #+#             */
/*   Updated: 2022/07/19 18:56:52 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_range_chk(const char *str, size_t i, int sign)
{
	long long	num;

	num = 0;
	while (ft_isdigit(str[i]))
	{	
		num = (num * 10) + (str[i] - '0');
		++i;
	}
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	return (ft_range_chk(str, i, sign));
}

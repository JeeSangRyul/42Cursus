/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:02:14 by sji               #+#    #+#             */
/*   Updated: 2022/07/15 21:44:35 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ten_len(int ten_nbr)
{
	int	len;

	len = 0;
	if (ten_nbr == 0)
		return (1);
	else if (ten_nbr < 0)
	{
		ten_nbr *= -1;
		len++;
	}
	while (ten_nbr != 0)
	{
		ten_nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	long long		nb;
	int				len;

	len = ten_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	nb = n;
	result[len--] = '\0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		result[0] = '0';
	while (nb)
	{
		result[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}

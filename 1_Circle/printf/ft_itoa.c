/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:53:27 by sji               #+#    #+#             */
/*   Updated: 2022/09/07 16:04:05 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ten_len(int ten_nbr)
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

static int	ten_unsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result;
	long long	nb;
	int			len;

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

char	*ft_uitoa(unsigned int n)
{
	char	*result;
	int		len;

	len = ten_unsigned(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n)
	{
		result[len--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}

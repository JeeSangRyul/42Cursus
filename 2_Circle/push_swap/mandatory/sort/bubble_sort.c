/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:40:27 by sji               #+#    #+#             */
/*   Updated: 2023/01/10 14:11:49 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	bubble_sort(int value[], int count)
{
	int	i;
	int	j;
	int	temp;

	i = count - 1;
	while (i >= 0)
	{
		j = 1;
		while (j <= i)
		{
			if (value[j - 1] > value[j])
			{
				temp = value[j - 1];
				value[j - 1] = value[j];
				value[j] = temp;
			}
			j++;
		}
		i--;
	}
}

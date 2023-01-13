/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:14:23 by jee               #+#    #+#             */
/*   Updated: 2023/01/13 16:22:32 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	select_pivot(int pivot[2], t_stack stack, int len)
{
	int		cnt;
	int		i;
	int		j;
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = stack.head;
	i = -1;
	while (++i < len)
	{
		tmp2 = stack.head;
		cnt = 0;
		j = -1;
		while (++j < len)
		{
			if (tmp1->content > tmp2->content)
				cnt++;
			tmp2 = tmp2->next;
		}
		if (cnt == len / 3)
			pivot[SMALL] = tmp1->content;
		else if (cnt == len / 3 * 2)
			pivot[BIG] = tmp1->content;
		tmp1 = tmp1->next;
	}
}

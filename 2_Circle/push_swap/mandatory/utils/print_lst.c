/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:48:26 by sji               #+#    #+#             */
/*   Updated: 2023/01/13 16:20:09 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	print_lst(t_list *list)
{
	t_node_op	*cur;
	char		*str;

	cur = list->head;
	while (cur)
	{
		str = cur->op;
		ft_putstr(str);
		ft_putstr("\n");
		cur = cur->next;
	}
}

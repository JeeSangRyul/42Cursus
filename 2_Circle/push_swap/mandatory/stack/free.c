/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:13:45 by sji               #+#    #+#             */
/*   Updated: 2023/01/13 15:46:29 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	free_all_stack(t_stacks *stacks)
{
	t_node	*tmp;
	t_node	*target;

	tmp = stacks->a.head;
	while (tmp)
	{
		target = tmp;
		tmp = tmp->next;
		free(target);
	}
}

void	free_list(t_list *list)
{
	t_node_op	*cur;
	t_node_op	*tmp;

	cur = list->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

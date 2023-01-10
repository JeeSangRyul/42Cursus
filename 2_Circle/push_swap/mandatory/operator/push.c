/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:39:27 by jee               #+#    #+#             */
/*   Updated: 2023/01/10 13:54:53 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	push(t_stack *from, t_stack *to)
{
	t_node	*target;

	if (!from->head)
		return (0);
	target = from->head;
	from->head = target->next;
	from->len--;
	if (from->head)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	target->next = to->head;
	if (target->next)
		target->next->prev = target;
	to->head = target;
	to->len++;
	if (to->len == 1)
		to->tail = to->head;
	return (1);
}

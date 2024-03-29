/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:35:33 by jee               #+#    #+#             */
/*   Updated: 2023/01/12 18:57:29 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	swap(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	if (stack->len < 2)
		return (0);
	else if (stack->len == 2)
		stack->tail = stack->head;
	a = stack->head;
	b = stack->head->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	a->prev = b;
	b->next = a;
	b->prev = NULL;
	stack->head = b;
	stack->head->next = a;
	return (1);
}

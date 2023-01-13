/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:30 by sji               #+#    #+#             */
/*   Updated: 2023/01/13 16:19:45 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	is_stick_two_operation(t_node_op *cur, char *op1, char *op2)
{
	if (cur->next && !ft_strcmp(cur->op, op1) && \
		!ft_strcmp(cur->next->op, op2))
		return (1);
	else if (cur->next && !ft_strcmp(cur->op, op2) && \
			!ft_strcmp(cur->next->op, op1))
		return (1);
	return (0);
}

void	delete_one_and_change(t_node_op *cur, char *op, t_stacks *stacks)
{
	t_node_op	*tmp;

	cur->op = op;
	tmp = cur->next;
	cur->next = cur->next->next;
	free(tmp);
	stacks->list.len--;
}

void	check_delete_one(t_node_op *cur, t_stacks *stacks)
{
	if (is_stick_two_operation(cur, "sa", "sb"))
		delete_one_and_change(cur, "ss", stacks);
	else if (is_stick_two_operation(cur, "ra", "rb"))
		delete_one_and_change(cur, "rr", stacks);
	else if (is_stick_two_operation(cur, "rra", "rrb"))
		delete_one_and_change(cur, "rrr", stacks);
	else if (is_stick_two_operation(cur, "rrr", "rb"))
		delete_one_and_change(cur, "rra", stacks);
	else if (is_stick_two_operation(cur, "rrr", "ra"))
		delete_one_and_change(cur, "rrb", stacks);
	else if (is_stick_two_operation(cur, "rr", "rrb"))
		delete_one_and_change(cur, "ra", stacks);
	else if (is_stick_two_operation(cur, "rr", "rra"))
		delete_one_and_change(cur, "rb", stacks);
}

void	optimization(t_stacks *stacks)
{
	t_node_op	*cur;

	cur = stacks->list.head;
	while (cur)
	{
		check_delete_one(cur, stacks);
		cur = cur->next;
	}
}

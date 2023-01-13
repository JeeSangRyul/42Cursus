/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:53:53 by sji               #+#    #+#             */
/*   Updated: 2023/01/13 16:18:16 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap_and_lstadd(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "sa") && swap(&stacks->a))
		lstadd_back_op(&stacks->list, "sa");
	else if (!ft_strcmp(op, "sb") && swap(&stacks->b))
		lstadd_back_op(&stacks->list, "sb");
	else if (!ft_strcmp(op, "ss") && (stacks->a.len >= 2) && \
			(stacks->b.len >= 2))
	{
		swap(&stacks->a);
		swap(&stacks->b);
		lstadd_back_op(&stacks->list, "ss");
	}
}

void	push_and_lstadd(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "pa") && push(&stacks->b, &stacks->a))
		lstadd_back_op(&stacks->list, "pa");
	else if (!ft_strcmp(op, "pb") && push(&stacks->a, &stacks->b))
		lstadd_back_op(&stacks->list, "pb");
}

void	rotate_and_lstadd(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "ra") && rotate(&stacks->a))
		lstadd_back_op(&stacks->list, "ra");
	else if (!ft_strcmp(op, "rb") && rotate(&stacks->b))
		lstadd_back_op(&stacks->list, "rb");
	else if (!ft_strcmp(op, "rr") && (stacks->a.len >= 2) && \
			stacks->b.len >= 2)
	{
		rotate(&stacks->a);
		rotate(&stacks->b);
		lstadd_back_op(&stacks->list, "rr");
	}
}

void	reverse_rotate_and_lstadd(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "rra") && reverse_rotate(&stacks->a))
		lstadd_back_op(&stacks->list, "rra");
	else if (!ft_strcmp(op, "rrb") && reverse_rotate(&stacks->b))
		lstadd_back_op(&stacks->list, "rrb");
	else if (!ft_strcmp(op, "rrr") && (stacks->a.len >= 2) && \
			(stacks->b.len >= 2))
	{
		reverse_rotate(&stacks->b);
		reverse_rotate(&stacks->a);
		lstadd_back_op(&stacks->list, "rrr");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:41:23 by jee               #+#    #+#             */
/*   Updated: 2023/01/12 22:36:22 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	operator(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "sa"))
		swap_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "sb"))
		swap_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "ss"))
		swap_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "pa"))
		push_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "pb"))
		push_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "ra"))
		rotate_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "rb"))
		rotate_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "rr"))
		rotate_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "rra"))
		reverse_rotate_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "rrb"))
		reverse_rotate_and_lstadd(op, stacks);
	else if (!ft_strcmp(op, "rrr"))
		reverse_rotate_and_lstadd(op, stacks);
}

void	operator_and_cnt(char *op, int cnt[3], t_stacks *stacks)
{
	if (!ft_strcmp(op, "ra"))
		cnt[RA_CNT] = cnt[RA_CNT] + 1;
	else if (!ft_strcmp(op, "rb"))
		cnt[RB_CNT] = cnt[RB_CNT] + 1;
	else if (!ft_strcmp(op, "pb"))
		cnt[PB_CNT] = cnt[PB_CNT] + 1;
	else if (!ft_strcmp(op, "pa"))
		cnt[PA_CNT] = cnt[PA_CNT] + 1;
	else if (!ft_strcmp(op, "rr"))
	{
		cnt[RA_CNT] = cnt[RA_CNT] + 1;
		cnt[RB_CNT] = cnt[RB_CNT] + 1;
	}
	if (!ft_strcmp(op, "ra"))
		operator("ra", stacks);
	else if (!ft_strcmp(op, "rb"))
		operator("rb", stacks);
	else if (!ft_strcmp(op, "pa"))
		operator("pa", stacks);
	else if (!ft_strcmp(op, "pb"))
		operator("pb", stacks);
	else if (!ft_strcmp(op, "rr"))
		operator("rr", stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:41:23 by jee               #+#    #+#             */
/*   Updated: 2023/01/10 13:54:38 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	operator(char *op, t_stacks *stacks)
{
	if (!ft_strcmp(op, "sa") && swap(&stacks->a))
		ft_putstr("sa\n");
	else if (!ft_strcmp(op, "sb") && swap(&stacks->b))
		ft_putstr("sb\n");
	else if (!ft_strcmp(op, "ss") && swap(&stacks->a) && swap(&stacks->b))
		ft_putstr("ss\n");
	else if (!ft_strcmp(op, "pa") && push(&stacks->b, &stacks->a))
		ft_putstr("pa\n");
	else if (!ft_strcmp(op, "pb") && push(&stacks->a, &stacks->b))
		ft_putstr("pb\n");
	else if (!ft_strcmp(op, "ra") && rotate(&stacks->a))
		ft_putstr("ra\n");
	else if (!ft_strcmp(op, "rb") && rotate(&stacks->b))
		ft_putstr("rb\n");
	else if (!ft_strcmp(op, "rr") && rotate(&stacks->a) && rotate(&stacks->b))
		ft_putstr("rr\n");
	else if (!ft_strcmp(op, "rra") && reverse_rotate(&stacks->a))
		ft_putstr("rra\n");
	else if (!ft_strcmp(op, "rrb") && reverse_rotate(&stacks->b))
		ft_putstr("rrb\n");
	else if (!ft_strcmp(op, "rrr") && reverse_rotate(&stacks->a) \
		&& reverse_rotate(&stacks->b))
		ft_putstr("rrr\n");
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

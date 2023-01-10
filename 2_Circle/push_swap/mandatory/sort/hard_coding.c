/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:15:42 by jee               #+#    #+#             */
/*   Updated: 2023/01/10 14:19:55 by sji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_three(t_stacks *stacks)
{
	t_stack	*stack;

	stack = &stacks->a;
	if (is_ascending(stack, 3))
		return ;
	else if (is_decending(stack, 3))
	{
		operator("sa", stacks);
		operator("rra", stacks);
	}
	if (stack->head->next->content > stack->head->next->next->content)
		operator("rra", stacks);
	if (!is_ascending(stack, 3) && stack->head->content \
		< stack->head->next->next->content)
		operator("sa", stacks);
	if (!is_ascending(stack, 3))
		operator("ra", stacks);
}

void	sort_three_or_under(t_stacks *stacks, int len)
{
	t_stack	*stack;

	stack = &stacks->a;
	if (len < 2)
		return ;
	else if (len == 2 && stack->head->content > stack->head->next->content)
		operator("sa", stacks);
	else if (len == 3)
		return (sort_three(stacks));
}

void	sort_four(t_stacks *stacks)
{
	int		min;
	t_node	*tmp;

	tmp = stacks->a.head;
	min = tmp->content;
	while (tmp)
	{
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	while (stacks->a.head->content != min)
		operator("ra", stacks);
	operator("pb", stacks);
	sort_three(stacks);
	operator("pa", stacks);
}

static void	get_min_node(int min[], int str[], t_stacks *stacks)
{
	int		i;
	t_node	*tmp;

	tmp = stacks->a.head;
	i = 0;
	while (tmp && i < 5)
	{
		str[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(str, 5);
	min[0] = str[0];
	min[1] = str[1];
}

void	sort_five(t_stacks *stacks)
{
	int	str[5];
	int	min[2];
	int	i;

	i = 0;
	get_min_node(min, str, stacks);
	while (i < 5)
	{
		if (stacks->a.head->content == min[0] || \
				stacks->a.head->content == min[1])
			operator("pb", stacks);
		else
			operator("ra", stacks);
		i++;
	}
	if (stacks->b.head->content < stacks->b.head->next->content)
		operator("sb", stacks);
	sort_three(stacks);
	operator("pa", stacks);
	operator("pa", stacks);
}

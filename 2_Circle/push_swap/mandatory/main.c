/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:32:19 by jee               #+#    #+#             */
/*   Updated: 2023/01/13 16:20:39 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	stack_null(t_stacks *stacks)
{
	stacks->a.head = NULL;
	stacks->a.tail = NULL;
	stacks->a.len = 0;
	stacks->b.head = NULL;
	stacks->b.tail = NULL;
	stacks->b.len = 0;
	stacks->list.head = NULL;
	stacks->list.tail = NULL;
	stacks->list.len = 0;
}

static void	sort_len(t_stacks *stacks, int len)
{
	if (len == 2)
		sort_three_or_under(stacks, len);
	else if (len == 3)
		sort_three(stacks);
	else if (len == 4)
		sort_four(stacks);
	else if (len == 5)
		sort_five(stacks);
	else
		sort_a_to_b(stacks, len);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			tmp;

	if (argc < 2)
		return (0);
	stack_null(&stacks);
	init_stacks(&stacks, argc, argv);
	if (is_ascending(&stacks.a, stacks.a.len))
	{
		free_all_stack(&stacks);
		return (0);
	}
	sort_len(&stacks, stacks.a.len);
	tmp = -1;
	while (tmp != stacks.a.len)
	{
		tmp = stacks.a.len;
		optimization(&stacks);
	}
	print_lst(&stacks.list);
	free_all_stack(&stacks);
	free_list(&stacks.list);
	return (0);
}

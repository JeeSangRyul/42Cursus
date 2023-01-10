/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:32:19 by jee               #+#    #+#             */
/*   Updated: 2023/01/10 22:52:02 by sji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void stack_null(t_stacks *stacks)
{
	stacks->a.head = NULL;
	stacks->a.tail = NULL;
	stacks->a.len = 0;


	stacks->b.head = NULL;
	stacks->b.tail = NULL;
	stacks->b.len = 0;


}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	stack_null(&stacks);
	init_stacks(&stacks, argc, argv);
	if (is_ascending(&stacks.a, stacks.a.len))
	{
		free_all_stack(&stacks);
		return (0);
	}
	if (stacks.a.len == 3)
		sort_three(&stacks);
	else if (stacks.a.len == 4)
		sort_four(&stacks);
	else if (stacks.a.len == 5)
		sort_five(&stacks);
	else
		sort_a_to_b(&stacks, stacks.a.len);
	free_all_stack(&stacks);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:33:30 by sji               #+#    #+#             */
/*   Updated: 2023/01/12 22:11:21 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int check_two_operation(t_node_op *cur, char *a, char *b)
{
    if (cur->next && ft_strcmp(cur->op, a) && ft_strcmp(cur->next->op, b))
        return (1);
    else if (cur->next && ft_strcmp(cur->op, b) && ft_strcmp(cur->next->op, a))
        return (1);
    return (0);
}

static void    combine_two_operation(t_node_op *cur, char *op, t_stacks *stacks)
{
    t_node_op   *tmp;

    cur->op = op;
    tmp = cur->next;
    cur->next = cur->next->next;
    free(tmp);
    stacks->list.len--;
}

static void    optimize_node(t_node_op *cur, t_stacks *stacks)
{
    if (check_two_operation(cur, "sa", "sb"))
        combine_two_operation(cur, "ss", stacks);
    else if (check_two_operation(cur, "ra", "rb"))
        combine_two_operation(cur, "rr", stacks);
    else if (check_two_operation(cur, "rra", "rrb"))
        combine_two_operation(cur, "rrr", stacks);
    else if (check_two_operation(cur, "sb", "sa"))
        combine_two_operation(cur, "ss", stacks);
    else if (check_two_operation(cur, "rb", "ra"))
        combine_two_operation(cur, "rr", stacks);
    else if (check_two_operation(cur, "rrb", "rra"))
        combine_two_operation(cur, "rrr", stacks);
    else if (check_two_operation(cur, "rrr", "rb"))
        combine_two_operation(cur, "rra", stacks);
    else if (check_two_operation(cur, "rrr", "ra"))
        combine_two_operation(cur, "rrb", stacks);
    else if (check_two_operation(cur, "rr", "rrb"))
        combine_two_operation(cur, "ra", stacks);
    else if (check_two_operation(cur, "rr", "rra"))
        combine_two_operation(cur, "rb", stacks);
}

void    optimization(t_stacks *stacks)
{
    t_node_op   *cur;

    cur = stacks->list.head;
    while (cur)
    {
        optimize_node(cur,stacks);
        cur = cur->next;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:15:42 by jee               #+#    #+#             */
/*   Updated: 2023/01/07 22:21:58 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    sort_three(t_stacks *stacks)
{
    t_stack *stack;

    stack = &stacks->a;
    if (is_ascending(stack, 3), is_decending(stack, 3))
    {
        if (is_ascending(stack, 3))
        return ;
        else if (is_decending(stack, 3))
        {
            operator("sa", stacks);
            operator("rra", stacks);
        }
        if (stack->head->next->content > stack->head->next->next->content)
        operator("rra", stacks);
        if (!is_ascending(stack, 3) && stack->head->content < stack->head->next->next->content)
        operator("sa",stacks);
        else if (!is_ascending(stack, 3))
        operator("ra", stacks);
    }
}

void    sort_three_or_under(t_stacks *stacks, int len)
{
    t_stack *stack;

    stack = &stacks->a;
    if (len < 2)
    return ;
    else if (len == 2 && stack->head->content > stack->head->next->content)
    operator("sa", stacks);
    else if (len == 3)
    return (sort_three(stacks));
}

void    sort_four(t_stacks *stacks)
{
    t_node  *tmp;
    int min;

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
    operator("pb",stacks);
    sort_three(stacks);
    operator("pa", stacks);
}

static void    get_min_node(int min, t_stacks *stacks)
{
    t_node  *tmp;

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
    operator("pb",stacks);
}

void    sort_five(t_stacks *stacks)
{   
    int min;

    min = 0;
    get_min_node(min, stacks);
    get_min_node(min, stacks);
    sort_three(stacks);
    operator("pa", stacks);
    operator("pa", stacks);
}

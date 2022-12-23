/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:15:42 by jee               #+#    #+#             */
/*   Updated: 2022/12/23 08:53:20 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sort_three(t_stacks *stacks)
{
    t_stack *stack;
    
    stack = &stacks->a;
    if (is_ascending(stack, 3), is_decending(stack, 3))
    {
        if (is_ascending(stack, 3)) //123
        return ;
        else if (is_decending(stack, 3)) //321
        {
            operator("sa", stack);
            operator("rra", stack);
        }
        if (stack->head->next->content > stack->head->next->next->content) //231  
        operator("rra", stack);
        if (!is_ascending(stack, 3) && stack->head->content < stack->head->next->next->content) //132, 213
        operator("sa",stack);
        else if (!is_ascending(stack, 3)) // 312
        operator("ra", stack);
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

static void    get_two_min_node(int min[2], t_stacks *stacks)
{
    t_node  *tmp;

    tmp = stacks->a.head;
    min[0] = tmp->content;
    min[1] = tmp->content;
    while (tmp)
    {
        if (min[0] > tmp->content)
        min[0] = tmp->content;
        tmp = tmp->next;
    }
    while (stacks->a.head->content != min[0])
        operator("ra", stacks);
    operator("pb",stacks);
    tmp = stacks->a.head;
    while (tmp)
    {
        if (min[1] > tmp->content)
        min[1] = tmp->content;
        tmp = tmp->next;
    }
    while (stacks->a.head->content != min[1])
        operator("ra", stacks);
    operator("pb",stacks);
}

void    sort_five(t_stacks *stacks)
{   
    int min[2];
    get_two_min_node(min, stacks);
    sort_three(stacks);
    operator("pa", stacks);
    operator("pa", stacks);
}

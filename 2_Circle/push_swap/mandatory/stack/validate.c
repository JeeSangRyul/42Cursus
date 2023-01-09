/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:32:17 by jee               #+#    #+#             */
/*   Updated: 2023/01/08 16:38:47 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void    validation_nodes(t_stacks *stacks)
{
    t_node  *tmp1;
    t_node  *tmp2;
    int i;
    int j;

    tmp1 = stacks->a.head;
    i = -1;
    while (++i < stacks->a.len)
    {
        tmp2 = stacks->a.head;
        j = -1;
        while (++j < stacks->a.len)
        {
            if (tmp1 != tmp2 && tmp1->content == tmp2->content)
                throw_error(stacks);
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
}

int is_ascending(t_stack *stack, int len)
{
    t_node  *tmp;
    int     i;

    tmp = stack->head;
    i = 0;
    while (i < len - 1)
    {
        if (tmp->content > tmp->next->content)
        return (0);
        tmp = tmp->next;
        i++;
    }
    return (1);
}

int is_decending(t_stack *stack, int len)
{
    t_node  *tmp;
    int     i;

    tmp = stack->head;
    i = 0;
    while (i < len - 1)
    {
        if (tmp->content < tmp->next->content)
        return (0);
        tmp = tmp->next;
        i++;
    }
    return (1);
}
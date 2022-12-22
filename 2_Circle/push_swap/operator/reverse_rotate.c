/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:39:02 by jee               #+#    #+#             */
/*   Updated: 2022/12/20 19:39:03 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int reverse_rotate(t_stack *stack)
{
    t_node *tail;

    if(stack->len < 2)
    return (0);
    tail = stack->tail;
    stack->tail = tail->prev;
    if (stack->tail)
        stack->tail->next = NULL;
    tail->next = stack->head;
    stack->head->prev = tail;
    stack->head = tail;
    stack->head->prev = NULL;
    if(stack->len == 2 && stack->tail)
        stack->tail->prev = stack->head;
    return (1);
}
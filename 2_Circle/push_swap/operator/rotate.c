/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:38:33 by jee               #+#    #+#             */
/*   Updated: 2022/12/20 19:38:49 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int rotate(t_stack *stack)
{
    t_node *head;

    if(stack->len < 2)
    return (0);
    head = stack->head;
    stack->head = stack->head->next;
    if(stack->head)
    stack->head->prev = NULL;
    head->prev = stack->tail;
    stack->tail->next = head;
    stack->tail = head;
    stack->tail->next = NULL;
    return (1);
}
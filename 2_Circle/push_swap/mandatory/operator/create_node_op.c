/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:54:29 by sji               #+#    #+#             */
/*   Updated: 2023/01/12 22:08:11 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_node_op	*create_node_op(char *op)
{
	t_node_op	*node;

	node = (t_node_op *)malloc(sizeof(t_node_op));
	if (!node)
		return (NULL);
	node->op = op;
	node->next = NULL;
	return (node);
}

void    lstadd_back_op(t_list *list, char *op)
{
    t_node_op   *node;
    t_node_op   *cur;

    node = create_node_op(op);
    cur = list->head;
    if (!cur)
    {
        list->head = node;
        list->tail = node;
        list->len++;
        return ;
    }
    else
    {
        while (cur->next)
        {
            cur = cur->next;
            cur->next = node;
            list->tail = node;
            list->len++;
        }
    }
}

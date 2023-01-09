/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:02:07 by jee               #+#    #+#             */
/*   Updated: 2023/01/08 20:56:01 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static  t_node  *new_node(char *argv, t_stacks *stacks)
{
    long long data;
    t_node  *node;

    data = ft_atoi(argv, stacks);
    printf("data = %d\n", (int)data);//!!
    if (data > 2147483647 || data < -2147483648)
        throw_error(stacks);
    node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->content = (int)data;
    printf("argv = %s\n", argv);//!!
    printf("node->content = %d\n", node->content);//!!
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

static  t_node *split_argv(char *argv, t_node *tmp, t_stack *stack, t_stacks *stacks)
{
    char **node_arr;

    node_arr = ft_split(argv, ' ');
    printf("첫번쨰 값은 = %s\n", argv); //!!
    while (*node_arr)
    {
        tmp->next = new_node(*node_arr, stacks);
        tmp->next->prev = tmp;
        tmp = tmp->next;
        stack->len++;
        node_arr++;
    }
    return (tmp);
}

static    t_node *init_stacks_head(char *argv, t_stack *stack, t_stacks *stacks) 
{
    char    *head;
    int     head_len;
    t_node  *tmp;
    long long  data;

    stack->len = 0;
    if(!ft_strchr(argv, ' '))
    {
        printf("첫번쨰 값은 = %s\n", argv); //!!
        data = ft_atoi(argv, stacks);
        printf("**data = %lld\n", data);//!!
        stack->head = new_node(argv, stacks);
        tmp = stack->head;
        stack->len++;
    }
    else
    {
        head_len = ft_strlen(argv) - ft_strlen(ft_strchr(argv, ' '));
        head = (char *)ft_calloc(head_len + 1, sizeof(char));
        ft_memmove(head, argv, head_len);
        stack->head = new_node(head, stacks);
        tmp = stack->head;
        stack->len++;
        tmp = split_argv(argv + head_len, tmp, stack, stacks);
        free(head);
    }
    printf("첫번째 값은 이것 이다 ->%d\n", stacks->a.head->content); //!!
    return (tmp);
}

void    free_all_stack(t_stacks *stacks)
{
    t_node  *tmp;
    t_node  *target;

    tmp = stacks->a.head;
    while(tmp)
    {
        target = tmp;
        tmp = tmp->next;
        free(target);
    }
}

void    init_stacks(t_stacks *stacks, int argc, char **argv)
{
    int     i;
    t_node  *temp;

    i = 1;
    temp = init_stacks_head(argv[i++], &stacks->a, stacks);
    printf("첫번쨰 값은 = %d\n", stacks->a.head->content); //!!
    while (i < argc)
    {
        if(!ft_strchr(argv[i], ' '))
        {
            temp->next = new_node(argv[i], stacks);
            temp->next->prev = temp;
            temp = temp->next;
            stacks->a.len++;
        }
        else
            temp = split_argv(argv[i], temp, &stacks->a, stacks);
        i++;
    }
    temp->next = NULL;
    stacks->a.tail = temp;
    ft_memset(&stacks->b, 0, sizeof(t_stack));
    validation_nodes(stacks);
}

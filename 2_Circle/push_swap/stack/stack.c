/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:02:07 by jee               #+#    #+#             */
/*   Updated: 2022/12/22 23:35:45 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static  t_node  *new_node(char *argv)
{
    long long data;
    t_node  *node;

    data = ft_atoi(argv);
    if (data > 2147483647 || data < -2147483648)
    return 0; //error
    node = (t_node *)malloc(sizeof(t_node));
    node->content = (int)data;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

static  t_node *split_argv(char *argv, t_node *tmp, t_stack *stack)
{
    char **node_arr;

    node_arr = ft_split(argv, ' ');
    while (*node_arr)
    {
        tmp->next = new_node(*node_arr);//' '으로 분리한 첫번째 값을 new_node에 넣어준다.
        tmp->next->prev = tmp;
        tmp = tmp->next;
        stack->len++;
        node_arr++;
    }
    return (tmp);
}

static    char *init_stacks_head(char *argv, t_stack *stack) 
{
    char    *head;
    int     head_len;
    t_node  *tmp;

    stack->len = 0;
    if(!ft_strchr(argv, ' ')) //argv[0]의 배열에서 ' '이 있는지 확인한다. 있다면 ' '의 주소를 반환한다.
    {
        stack->head = new_node(argv); //stack의 헤더에게 첫 노드를 쥐어준다.
        tmp = stack->head;
        stack->len++;
    }
    else
    {
        head_len = ft_strlen(argv) - ft_strlen(ft_strchr(argv, ' '));//첫 인자값이 문자열로 들어올 경우, 문자열 안에 첫 문자의 길이를 뽑아낸다.
        head = (char *)ft_calloc(head_len + 1, sizeof(char));//head_len + 1을 전부 null값으로 초기화
        ft_memmove(head, argv, head_len);//head에 argv를 head_len길이만큼 복사한다.
        stack->head = new_node(head);
        tmp = stack->head;
        stack->len++;
        tmp = split_argv(argv + head_len, tmp, stack);
        free(head);
    }
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

    i = 0;
    temp = init_stacks_head(argv[i++], &stacks->a); // 첫 인자값을 정하기 위해서 argv[0]을 보내준다.
    //temp는 마지막 노드를 가리키고 있다.
    //init_stacks_head를 통해 stack->head는 첫 노드를 가리키고 있다.
    //temp는 마지막에 stack->tail에 넣어주기 위해서 선언했다.
    while (i < argc - 1)
    {
        if(!ft_strchr(argv[i], ' '))
        {
            temp->next = new_node(argv[i]);
            temp->next->prev = temp;
            temp = temp->next;
            stacks->a.len++;
        }
        else
            temp = split_argv(argv[i], temp, &stacks->a);
        i++;
    }
    temp->next = NULL;
    stacks->a.tail = temp;
    ft_memset(&stacks->b, 0, sizeof(t_stack));//b stack에 null값을 t_stack크기만큼 넣어준다.
    validate_note(stacks);
}

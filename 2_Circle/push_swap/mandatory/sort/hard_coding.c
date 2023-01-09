/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 00:15:42 by jee               #+#    #+#             */
/*   Updated: 2023/01/08 21:18:48 by jee              ###   ########.fr       */
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
        if (!is_ascending(stack, 3) && stack->head->content \
            < stack->head->next->next->content)
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

void bubbleSort(int value[], int count)
{
  int   i;
  int   j;
  int   temp;

  i = count - 1;
  while (i >= 0)
  {
    j = 1;
    while (j <= i)
    {
        if (value[j - 1] > value[j])
        {
            temp = value[j - 1];
            value[j - 1] = value[j];
            value[j] = temp;
        }
        j++;
    }
    i--;
  }
}

static void    get_min_node(int min[], int str[], t_stacks *stacks)
{
    t_node  *tmp;
    int     i;

    tmp = stacks->a.head;
    i = 0;
    while (tmp && i < 5)
    {
        str[i] = tmp->content;
        tmp = tmp->next;
        i++;
    }
    printf("array = %d %d %d %d %d\n", str[0], str[1], str[2], str[3],str[4]);
    bubbleSort(str, 5);//정렬된 str
    printf("array = %d %d %d %d %d\n", str[0], str[1], str[2], str[3],str[4]);
    min[0] = str[0];
    min[1] = str[1];
}

void    sort_five(t_stacks *stacks)
{   
    int str[5];
    int min[2];
    int i;

    i = 0;
    get_min_node(min, str, stacks);
    while (i < 5)
    {
        if(stacks->a.head->content == min[0] ||\
            stacks->a.head->content == min[1])
            operator("pb", stacks);
        else
            operator("ra", stacks);
        i++;
    }
    sort_three(stacks);
    operator("pa", stacks);
    operator("pa", stacks);
}

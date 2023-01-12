/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:02:07 by jee               #+#    #+#             */
/*   Updated: 2023/01/12 22:23:10 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static t_node	*new_node(char *argv, t_stacks *stacks)
{
	long long	data;
	t_node		*node;

	data = ft_atoi(argv, stacks);
	if (data > 2147483647 || data < -2147483648)
		throw_error(stacks);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = (int)data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static t_node	*split_av(char *av, t_node *tmp, t_stack *a, t_stacks *b)
{
	char	**node_arr;

	node_arr = ft_split(av, ' ');
	if (!node_arr[0])
	{
		free(node_arr);
		throw_error(b);
	}
	while (*node_arr)
	{
		tmp->next = new_node(*node_arr, b);
		tmp->next->prev = tmp;
		tmp = tmp->next;
		a->len++;
		node_arr++;
	}
	return (tmp);
}

static t_node	*init_stacks_head(char *argv, t_stack *stack, t_stacks *stacks)
{
	char		*head;
	int			head_len;
	long long	data;
	t_node		*tmp;

	stack->len = 0;
	if (!ft_strchr(argv, ' '))
	{
		data = ft_atoi(argv, stacks);
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
		tmp = split_av(argv + head_len, tmp, stack, stacks);
		free(head);
	}
	return (tmp);
}

void	init_stacks(t_stacks *stacks, int argc, char **argv)
{
	int		i;
	t_node	*temp;

	i = 1;
	temp = init_stacks_head(argv[i++], &stacks->a, stacks);
	while (i < argc)
	{
		if (!ft_strchr(argv[i], ' '))
		{
			temp->next = new_node(argv[i], stacks);
			temp->next->prev = temp;
			temp = temp->next;
			stacks->a.len++;
		}
		else
			temp = split_av(argv[i], temp, &stacks->a, stacks);
		i++;
	}
	temp->next = NULL;
	stacks->a.tail = temp;
	ft_memset(&stacks->b, 0, sizeof(t_stack));
	validation_nodes(stacks);
}

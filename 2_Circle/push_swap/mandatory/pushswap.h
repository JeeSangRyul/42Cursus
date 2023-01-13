/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:04:30 by jee               #+#    #+#             */
/*   Updated: 2023/01/13 16:22:20 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

# define SMALL 0
# define BIG 1
# define RA_CNT 0
# define PB_CNT 1
# define PA_CNT 1
# define RB_CNT 2

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		len;
}				t_stack;

typedef struct s_node_op
{
	char				*op;
	struct s_node_op	*next;
}				t_node_op;

typedef struct s_list
{
	t_node_op		*head;
	t_node_op		*tail;
	int				len;
}				t_list;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
	t_list	list;
}				t_stacks;

//== operator
void		lstadd_back_op(t_list *list, char *op);
void		operator(char *op, t_stacks *stacks);
void		operator_and_cnt(char *op, int cnt[3], t_stacks *stacks);
void		swap_and_lstadd(char *op, t_stacks *stacks);
void		push_and_lstadd(char *op, t_stacks *stacks);
void		rotate_and_lstadd(char *op, t_stacks *stacks);
void		reverse_rotate_and_lstadd(char *op, t_stacks *stacks);
void		optimization(t_stacks *stacks);

//== sort
void		bubble_sort(int value[], int count);
void		sort_three(t_stacks *stacks);
void		sort_three_or_under(t_stacks *stacks, int len);
void		sort_four(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		select_pivot(int pivot[2], t_stack stack, int len);
void		sort_a_to_b(t_stacks *stacks, int len);
void		sort_b_to_a(t_stacks *stacks, int len);
int			swap(t_stack *stack);
int			rotate(t_stack *stack);
int			reverse_rotate(t_stack *stack);
int			push(t_stack *from, t_stack *to);

//== stack
void		free_all_stack(t_stacks *stacks);
void		free_list(t_list *list);
void		init_stacks(t_stacks *stacks, int argc, char **argv);
void		validation_nodes(t_stacks *stacks);
int			is_ascending(t_stack *stack, int len);
int			is_decending(t_stack *stack, int len);

//== utils
void		throw_error(t_stacks *stacks);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
long long	ft_atoi(const char *str, t_stacks *stacks);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_putstr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		print_lst(t_list *list);

#endif
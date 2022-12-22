/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:27:56 by jee               #+#    #+#             */
/*   Updated: 2022/12/22 23:41:00 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void    sort_three_or_under_chunk(t_stacks *stacks, int len)
{
    t_stack *stack;

    stack = &stacks->a;
    if (len < 2)
    return ;
    else if (len == 2 && stack->head->content > stack->head->next->content)
        operator("sa", stacks);
    else if (len == 3)
        sort_three(stacks);
}

static void    move_a_to_b(t_stacks *stacks, int pivot[2], int cnt[3], int len)
{
    while (len--)
    {
        if (stacks->a.head->content >= pivot[BIG])
            operator_and_cnt("ra", cnt, stacks);
        else
        {
            operator_and_cnt("pb", cnt, stacks);
            if (stacks->b.head->content >= pivot[SMALL])
            {
                if (stacks->b.len > 1 && len && stacks->a.head->content >= pivot[BIG])
                {
                    operator_and_cnt("rr", cnt, stacks);
                    len--;
                }//어차피 small보다 크고 big보다 작은 놈들은 b스택 아래로 보낼 상황이지만,
                //a header가 large보다 클 경우 ra를 실행해야하기 때문에 명령어를 줄이기 위해,
                //rr을 해준것이다.
                else
                    operator_and_cnt("rb", cnt, stacks);
            }
        }
    }
    
}

static void rotate_back(t_stacks *stacks, int ra_cnt, int rb_cnt)
{
	while (ra_cnt > 0 || rb_cnt > 0)
	{
		if (ra_cnt > 0 && rb_cnt > 0)
			operator("rrr", stacks);
		else if (ra_cnt > 0)
			operator("rra", stacks);
		else if (rb_cnt > 0)
			operator("rrb", stacks);
		ra_cnt--;
		rb_cnt--;
	}
}

void    sort_a_to_b(t_stacks *stacks, int len)
{
    int pivot[2];
    int cnt[3];

    if(len <= 3)
        return (sort_three_or_under_chunk(stacks, len));
    ft_memset(cnt, 0, sizeof(cnt));
    select_pivot(pivot, stacks->a, len);
    move_a_to_b(stacks, pivot, cnt, len);
    rotate_back(stacks, cnt[RA_CNT], cnt[RB_CNT]);
    sort_a_to_b(stacks, cnt[RA_CNT]); //a스택에 3개가 남겨질 때까지 재귀함수를 돈다.
    sort_b_to_a(stacks, cnt[RB_CNT]);
    sort_b_to_a(stacks, cnt[PB_CNT] - cnt[RB_CNT]);
}
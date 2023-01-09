/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jee <jee@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:32:19 by jee               #+#    #+#             */
/*   Updated: 2023/01/08 20:56:04 by jee              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
    t_stacks    stacks;

    if (argc < 2)
        return (0);
    init_stacks(&stacks, argc, argv);
    if (is_ascending(&stacks.a, stacks.a.len))
    {
        free_all_stack(&stacks);
        return (0);
    }
    if (stacks.a.len == 3)
        sort_three(&stacks);
    else if (stacks.a.len == 4)
        sort_four(&stacks);
    else if (stacks.a.len == 5)
        sort_five(&stacks);
    else
        sort_a_to_b(&stacks, stacks.a.len);
    free_all_stack(&stacks);
    return (0);
}

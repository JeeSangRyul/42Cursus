/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:22:01 by sji               #+#    #+#             */
/*   Updated: 2022/07/18 21:43:35 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p_save_next;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		p_save_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = p_save_next;
	}	
	*lst = NULL;
}

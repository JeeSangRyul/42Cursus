/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:42:36 by sji               #+#    #+#             */
/*   Updated: 2022/07/19 15:33:06 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p_header;
	t_list	*new_next;
	t_list	*p;

	p_header = NULL;
	p = lst;
	if (!p)
		return (NULL);
	while (p)
	{
		new_next = ft_lstnew(f(p->content));
		if (!new_next)
		{
			ft_lstclear(&p_header, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&p_header, new_next);
		p = p->next;
	}
	return (p_header);
}

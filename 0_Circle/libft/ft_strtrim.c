/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:03:43 by sji               #+#    #+#             */
/*   Updated: 2022/07/15 21:46:36 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_str(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		rear;
	int		i;
	char	*str;

	if (s1 == 0 || set == 0)
		return ((char *)s1);
	front = 0;
	rear = ft_strlen(s1) - 1;
	while (s1[front] && check_str(s1[front], set))
		front++;
	while (s1[rear] && check_str(s1[rear], set) && rear > front)
		rear--;
	str = (char *)malloc(sizeof(char) * (rear - front + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (front <= rear)
		str[i++] = s1[front++];
	str[i] = '\0';
	return (str);
}

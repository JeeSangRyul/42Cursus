/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:03:31 by sji               #+#    #+#             */
/*   Updated: 2022/07/15 21:47:02 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_ptr;
	int		i;

	if (!s)
		return (NULL);
	s_ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_ptr[i] = f(i, s[i]);
		i++;
	}
	s_ptr[i] = '\0';
	return (s_ptr);
}

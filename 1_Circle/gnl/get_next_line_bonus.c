/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:06:04 by sji               #+#    #+#             */
/*   Updated: 2022/11/30 15:58:39 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_one_line(char **backup, char *buf)
{
	char	*line;
	char	*new_temp;
	int		num;

	line = NULL;
	num = check_newline(*backup);
	if (num == -1)
	{
		if (*backup[0] != '\0')
			line = ft_strndup(*backup, 0, ft_strlen(*backup));
		free(*backup);
		*backup = NULL;
	}
	else
	{
		line = ft_strndup(*backup, 0, num + 1);
		new_temp = ft_strndup(*backup, num + 1, ft_strlen(*backup) - num);
		free(*backup);
		*backup = new_temp;
	}
	free(buf);
	return (line);
}

static char	*ft_readsize(int fd, char **backup, char *buf)
{
	char	*temp;
	int		read_size;
	int		num;

	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		temp = ft_strjoin(*backup, buf);
		free(*backup);
		*backup = temp;
		num = check_newline(*backup);
		if (num != -1)
			return (get_one_line(backup, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (get_one_line(backup, buf));
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup[OPEN_MAX];

	buf = (char *)(malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buf)
		return (NULL);
	if (fd < 0)
	{
		free(buf);
		return (NULL);
	}
	if (BUFFER_SIZE <= 0 && read(fd, buf, 0) == -1)
	{
		free(buf);
		return (NULL);
	}
	if (backup[fd] != NULL && check_newline(backup[fd]) != -1)
		return (get_one_line(&backup[fd], buf));
	if (backup[fd] == NULL)
		backup[fd] = ft_strndup("", 0, 0);
	return (ft_readsize(fd, &backup[fd], buf));
}

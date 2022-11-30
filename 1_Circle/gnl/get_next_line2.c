/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sji <sji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:38:40 by sji               #+#    #+#             */
/*   Updated: 2022/11/30 15:48:17 by sji              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line2.h"

t_gnl_list	*ft_make_node(int fd) //초기화해주고 넘겨주는 역할
{
	t_gnl_list	*node;

	node = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	node->fd = fd;
	node->prev = NULL;
	node->next = NULL;
	node->buff = NULL;
	return (node);
}

t_gnl_list	*ft_find_node(t_gnl_list **backup, int fd)
{
	t_gnl_list	*node;
	t_gnl_list	*new_node;

	if (*backup == NULL) // 리스트에 어떠한 것도 없으면 일단 초기화 해주는 역할
	{
		*backup = ft_make_node(fd);//내 코드에서는 ft_strndup("",0,0);이부분에 해당한다.
		return (*backup);
	}
	node = *backup;
	while (node->next)
	{
		if (node->fd == fd)//마지막 노드까지 가면서 fd값을 확인해서 같은값이 있다면 반환한다.
			return (node);
		node = node->next;
	}
	new_node = ft_make_node(fd);
	node->next = new_node;
	new_node->prev = node;
	return (new_node);
}

void  ft_del_node(t_gnl_list  **list, int fd)
{
  t_gnl_list *node;

  node = ft_find_node(list, fd);
  if (node->backup) // node->backup에 무엇인가 있다면 free해줄 필요없지만 없을경우
    //해당 fd의 node를 free해준다.
    return ;
  if (*list->fd == node->fd)//첫번째 노드가 지우고자 하는 node일때
    *list = node->next;
  if (node->next) //첫번째 노드가 아닌상태에서 지우고자 하는 node 앞뒤 node에 값을 채워주는 과정
    node->next->prev = node->prev;
  if (node->prev)
    node->prev->next = node->next;
  free(node);//그리고 혼자가 된 node를 free해준다.
  node = NULL;
}

char	*ft_read_file(int fd, char *backup)
{
	char	*buffer;
	ssize_t	read_size; //부호가 있는 가장 큰 int
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(backup , '\n') && read_size != 0)
	{
    if (read_size < 0)
    {
      if (backup)
        free(backup);
        //조건문을 써서 backup에 아무것도 없을때 free할 경우,
      //free하지 않아도 되는데 free되는 것을 막았다
      free(buffer);//그동안 읽어왔던 buffer를 free해준다.
      return (NULL);
    }
    buffer[read_size] = '\0';
    backup = ft_strjoin(backup , buffer);
	  read_size = read(fd, buffer, BUFFER_SIZE);
	}
  free(buffer); // read_size가 0일경우 buffer에는 읽어올 것이 없으므로 그냥 free해주면 된다.
  return (backup);//여기 나왔다는 말은 backup에 \n이 있거나, 더이상 읽을 것이 없거나 error일 경우
}

char *get_next_line(int fd)
{
	static t_gnl_list	*backup;
	t_gnl_list			*node;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = ft_find_node(&backup, fd);//해당 fd의 노드가 저장됨 , 없으면 만들어서 저장됨.
	node->buff = ft_read_file(fd, node->buff);
  if (!node->buff)
  {
    ft_del_node(&backup, fd);//해당 fd의 노드를 제거해주는 함수
    return (NULL);
  }
  line = ft_get_line(node->backup);//line에 한 줄 저장.
  node->backup = ft_update_backup(node->backup);//\n앞을 출력해주고 남은 것 새롭게 갱신
  ft_del_node(&backup, fd); 
  //쓰이지 않는 backup파일은 지워준다. 단지 backup의 역할은 \n을기준으로 뽑아주고
  //출력되지 못한 친구를 저장해주는 역할밖에 하지않는다.
  //만약 backup에 무엇인가 들어있다면 아무것도 하지않고 return을 해준다.
  return (line);
}

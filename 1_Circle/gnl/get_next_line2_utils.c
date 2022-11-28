
#include "get_next_line2.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *cache, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(ft_strlen(cache) + ft_strlen(buffer) + 1);
	if (!str)
	{
		if (cache) //여러번 cache가 들어오고 기존의 cache는 항상 free해줘야한다.
			free(cache);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (cache && cache[i])
	{
		str[i] = cache[i];
		i++;
	}
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	if (cache) 
    //cache는 알아서 함수가 없어지지만 cache로 받아온 memory는 따로 할당해주어야한다.
		free(cache);
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}

char  *ft_get_line(char *backup) //라인 하나 빼주는 역할
{
  int   i;
  char *str;
  
  i = 0;
  if (!backup[i])
    return (NULL);
  while (backup[i] && backup[i] != '\n')
    i++; //개행이나 \0 만나기 전까지 i를 읽는다.
  str = (char *)malloc(sizeof(char) * (i + 2));// 개수라서 먼저 +1을 해주고, null값들어가야해서 +1해준다.
  if (!str)
    return (NULL);
  i = 0;
  while (cache[i] && cache[i] != '\n')
  {
    str[i] = cache[i];
    i++;
  }
  if (cache[i] == '\n')
  {
    str[i] = cache[i];
    i++;
  }
  str[i] = '\0';
  return (str);
}

char  *ft_update_backup(char *backup) //  '\n'경계로 하나 뺴준다음 새로운 backup만들어주는 역할
{
  int   i;
  int   j;
  char *str;

  i = 0;
  while (backup[i] && backup[i] != '\n')
    i++;
  if (!backup[i] || !backup[i + 1]) //전자의 경우 backup에 남아있는것이 아무것도 업다는 의미
    //후자의 경우 \n다음이 null일 경우이다. 어차피 \n까지 출력할거기 때문에 free해줘도된다.
  {
    free(backup);
    return (NULL);
  }
  str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
  if (!str)
  {
    free(backup);
    return (NULL);
  }
  i++;
  j = 0;
  while (backup[i])
    str[j] = backup[i++];
  str[j] = '\0';
  free(backup);//새로운 backup위해 기존의 backup을 free해주는 것이다.
  return (str);
}

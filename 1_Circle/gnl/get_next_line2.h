#ifndef GET_NEXT_LINE_H2
# define GET_NEXT_LINE_H2

# include <stdlib.h>
# include <unistd.h>

typedef s_gnl_list
{
    int     			fd;
    char    			*backup;
    struct s_gnl_list   *next;
	struct s_gnl_list	*prev;
}   t_gnl_list;

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *cache, char *buffer);
char	*ft_strchr(char *str, int c);
void	ft_del_node(t_list **list, int fd);
t_list	*ft_find_node(t_list **list, int fd);
t_list	*ft_make_node(int fd);
char	*ft_read_file(int fd, char *cache);
char	*ft_get_line(char *cache);
char	*ft_update_cache(char *cache);
char	*get_next_line(int fd);

#endif

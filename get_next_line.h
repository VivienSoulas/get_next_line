#ifndef GET_NEXT_LIVE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define  BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
int		check_new_line(t_list *list);

#endif
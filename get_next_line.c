#include "get_next_line.h"
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c


int	main(void)
{
	int		fd;
	// char	*lineread;

	fd = 0;
	fd = open ("fearandloathinginlasvegas.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	get_next_line(fd);
	// while ((lineread = get_next_line(fd)) != 0)
	// {
	// 	printf("%s\n", lineread);
	// 	free(lineread);
	// }
	close(fd);
	return (0);
}

// create a new node with the content = to buffer
// place the new node at the end of the list
void	join_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = buffer;
	last_node = ft_lstlast(*list);
	if (*list == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->next = NULL;
}


// create node in the list until we find a \n
// when found we create a new node that we add at the end of the list
// the node created has for content the buffer
void	create_list(t_list **list, int fd)
{
	int		bytesread;
	char	*buffer;

	bytesread = 0;
	while (!check_new_line(*list))
	{
		buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(buffer);
			return ;
		}
		buffer[bytesread] = '\0';
		join_node(list, buffer);
	}
	return ;
}

char	*find_line(t_list *new_list)
{
	char	*next_line;
	t_list	*current;
	int		i;
	int		k;
	int		line_len;

	current = new_list;
	while (current)
	{
		i = 0;
		while (current->content[i] != '\n')
		{
			line_len++;
			i++;
			if (current->content[i] == '\n')
				break ;

		}
		current = current->next;
	}
	next_line = malloc ((line_len + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	current = new_list;
	k = 0;
	while (current)
	{
		i = 0;
		while (current->content[i]) // seg fault
		{
			next_line[k] = current->content[i];
			i++;
			k++;
			if (current->content[i] == '\n')
			{
				next_line[k] = current->content[i];
				next_line[k + 1] = '\0';
				return (next_line);
			}
			current = current->next;
		}
	}
	return (next_line);
}


char	*get_next_line(int fd)
{
	static t_list	*new_list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	new_list = NULL;
	create_list(&new_list, fd);
	if (new_list == NULL)
		return (NULL);

	next_line = find_line(new_list);
	// clear_list(&new_list);
	return (next_line);
}

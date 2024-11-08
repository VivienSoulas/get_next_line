#include "get_next_line.h"

// int	main(void)
// {
// 	int		fd;
// 	char	*lineread;

// 	fd = 0;
// 	fd = open ("fearandloathinginlasvegas.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	// lineread = get_next_line(fd);
// 	// printf("%s\n", lineread);
// 	while ((lineread = get_next_line(fd)) != 0)
// 	{
// 		printf("%s\n", lineread);
// 		free(lineread);
// 	}
// 	close(fd);
// 	return (0);
// }

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	read_and_stash(&stash, fd);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line && line[0] == '\0')
	{
		ft_free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// uses read() to add text to the stash
void	read_and_stash(t_list **stash, int fd)
{
	char	*buffer;
	int		bytesread;

	bytesread = 0;
	while (!ft_found_new_line(*stash))
	{
		buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		bytesread = read (fd, buffer, BUFFER_SIZE);
		if ((bytesread == 0) || bytesread < 0)
		{
			free(buffer);
			return ;
		}
		buffer[bytesread] = '\0';
		ft_add_to_stash(stash, buffer, bytesread);
		free(buffer);
	}
}

// add buffer to the end of stash
void	ft_add_to_stash(t_list **stash, char *buffer, int bytesread)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc (sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc (sizeof(char) * (bytesread + 1));
	if (new_node->content == NULL)
	{
		free(new_node);
		return ;
	}
	i = -1;
	while (++i < bytesread && buffer[i])
		new_node->content[i] = buffer[i];
	new_node->content[i] = '\0';
	if (*stash == NULL)
		*stash = new_node;
	else
	{
		last = ft_last_node(*stash);
		last->next = new_node;
	}
}

// extract the line from stash to new_line
// stopping after the first \n
void	extract_line(t_list *stash, char **next_line)
{
	int	i;
	int	j;

	ft_generate_line(next_line, stash);
	if (*next_line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*next_line)[j++] = stash->content[i];
				break ;
			}
			(*next_line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*next_line)[j] = '\0';
}

// goes through the last node until its end or a '\n'
// allocate memory for the node content of size remaining after \n
// fill the node content with remaining text
// free stash
void	clean_stash(t_list **stash)
{
	t_list	*last;
	int		i;

	if (stash == NULL)
		return ;
	last = ft_last_node(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	ft_fill_last_node(stash, i, last);
}

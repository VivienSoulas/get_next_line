#include "get_next_line.h"

int	ft_found_new_line(t_list *stash)
{
	int		i;
	t_list	*last;

	if (stash == NULL)
		return (0);
	last = ft_last_node(stash);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_last_node(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}

// calculate the numbers of char in until '\n'included
void	ft_generate_line(char **next_line, t_list *stash)
{
	int	i;
	int	line_len;

	line_len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				line_len++;
				break ;
			}
			line_len++;
			i++;
		}
		stash = stash->next;
	}
	*next_line = malloc (sizeof(char) * (line_len + 1));
}

void	ft_fill_last_node(t_list **stash, int i, t_list *last)
{
	t_list	*temp;
	int		j;
	int		len;

	len = 0;
	while (last->content[len])
		len++;
	temp = malloc (sizeof(t_list));
	if (temp == NULL)
		return ;
	temp->content = malloc (sizeof(char) * (len - i) + 1);
	if (temp->content == NULL)
	{
		free(temp);
		return ;
	}
	j = 0;
	while (last->content[i])
		temp->content[j++] = last->content[i++];
	temp->content[j] = '\0';
	ft_free_stash(*stash);
	temp->next = NULL;
	*stash = temp;
}

void	ft_free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	while (stash)
	{
		current = stash;
		next = stash->next;
		free(current->content);
		free(current);
		stash = next;
	}
}

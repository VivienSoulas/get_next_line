#include "get_next_line_bonus.h"

// modified strchr to return int (0 or 1) for bool
int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

// modified strjoin
// if next_line == null
// malloc a pointer to '\0' to avoid concatinating to unallocated memory
// if next_line exist, copy next_line in new array
// copy buf in new array after next_line
char	*ft_strjoin(char *next_line, char *buf)
{
	char	*str;
	int		i;
	int		j;

	if (next_line == NULL)
	{
		next_line = malloc (sizeof(char) * 1);
		if (next_line == NULL)
			return (NULL);
		next_line[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(next_line) + ft_strlen(buf) + 1));
	if (str == NULL)
	{
		free(next_line);
		return (NULL);
	}
	i = -1;
	if (next_line)
		while (next_line[++i])
			str[i] = next_line[i];
	j = 0;
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	free(next_line);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_free(char *next_line, char *buf)
{
	if (next_line)
	{
		free(next_line);
		free(buf);
		return ;
	}
	free(buf);
	return ;
}

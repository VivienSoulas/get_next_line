/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:17 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/28 11:28:37 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char *next_line, char *buf)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(next_line) + ft_strlen(buf) + 1));
	if (str == NULL)
	{
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

char	*ft_free_and_join(char *next_line, char *buf)
{
	char	*temp;

	if (next_line == NULL)
	{
		next_line = malloc (sizeof(char) * 1);
		if (next_line == NULL)
			return (NULL);
		next_line[0] = '\0';
	}
	temp = ft_strjoin(next_line, buf);
	free(next_line);
	return (temp);
}

void	free_static(char **next_line)
{
	if (*next_line != NULL)
		free(*next_line);
	*next_line = NULL;
}

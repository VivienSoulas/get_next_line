/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:10 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/21 14:38:37 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// int	main(void)
// {
// // 	int		fd;
// // 	int		fd1;
// 	int		fd2;
// 	int		i;
// 	char	*lineread;

// 	// fd = 0;
// 	// fd1 = 0;
// 	fd2 = 0;
// 	i = 0;
// 	// fd = open ("halloween.txt", O_RDONLY);
// 	// fd1 = open ("fightclub.txt", O_RDONLY);
// 	//fd2 = open ("fearandloathinginlasvegas.txt", O_RDONLY);
// 	fd2 = open ("test.txt", O_RDONLY);
// 	if (/*fd < 0 || fd1 < 0 || */fd2 < 0)
// 		return (1);
// 	while (i < 5)
// 	{
// 		lineread = get_next_line(fd2);
// 		printf("line %i from text 1 =\n", i);
// 		printf("|%s|\n", lineread);
// 		free(lineread);
// 		// lineread = get_next_line(fd1);
// 		// printf("line %i from text 2 =\n", i);
// 		// printf("%s\n", lineread);
// 		// free(lineread);
// 		// lineread = get_next_line(fd);
// 		// printf("line %i from text 3 =\n", i);
// 		// printf("%s\n", lineread);
// 		// free(lineread);
// 		i++;
// 	}
// 	close(fd2);
// 	// close(fd1);
// 	// close(fd2);
// 	return (0);
// }

// 1. read() and copy all characters from the file fd until '/n' is found
// 2. extract the line from array to the new array (line) including '\n'
// 3. remove the char before '/n' et return the array with everything afterwards
char	*get_next_line(int fd)
{
	static char	*next_line [1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (next_line[fd] != NULL)
			free_static(&next_line[fd]);
		return (NULL);
	}
	next_line[fd] = ft_read_and_copy(fd, next_line[fd]);
	if (next_line[fd] == NULL)
		return (NULL);
	line = ft_get_line(next_line[fd]);
	if (line == NULL)
	{
		free_static(&next_line[fd]);
		return (NULL);
	}
	next_line[fd] = ft_new_next_line(next_line[fd]);
	return (line);
}

// read the file fd
// check for '/n'in next_line
// join the buffer (buf) to the exiting string next_line
char	*ft_read_and_copy(int fd, char *next_line)
{
	int		bytesread;
	char	*buf;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (free_static(&next_line), NULL);
	bytesread = 1;
	while (bytesread != 0 && !ft_strchr(next_line, '\n'))
	{
		bytesread = read(fd, buf, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buf);
			return (free_static(&next_line), NULL);
		}
		buf[bytesread] = '\0';
		next_line = ft_free_and_join(next_line, buf);
		if (next_line == NULL)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (next_line);
}

// extract the line from the array/string next_line including the '/n'
char	*ft_get_line(char *next_line)
{
	char	*line;
	int		i;

	if (next_line[0] == '\0')
		return (NULL);
	i = 0;
	while (next_line[i] != '\n' && next_line[i])
		i++;
	if (next_line[i] == '\0')
		i--;
	line = malloc (sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	line[i + 1] = '\0';
	while (i >= 0)
	{
		line[i] = next_line[i];
		i--;
	}
	return (line);
}

// create a new array and fill it with the remainng of text after '\n' (if any)
char	*ft_new_next_line(char *next_line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (next_line[i] != '\n' && next_line[i])
		i++;
	if (next_line[i] == '\0')
	{
		free(next_line);
		return (NULL);
	}
	new_line = malloc (sizeof(char) * (ft_strlen(next_line) - i + 1));
	if (new_line == NULL)
	{
		free(next_line);
		return (NULL);
	}
	j = 0;
	i++;
	while (next_line[i])
		new_line[j++] = next_line[i++];
	new_line[j] = '\0';
	free(next_line);
	return (new_line);
}

//int main(void)
//{
//	int fd = open("test.txt", O_RDONLY);

//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	//close(fd);
//	//printf("%s", get_next_line(fd));
//	//fd = open("test.txt", O_RDONLY);
//	//printf("new line \n");
//	//printf("%s", get_next_line(fd));
//	//printf("%s", get_next_line(fd));
//	return (0);
//}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:14 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/21 10:56:43 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read_and_copy(int fd, char *next_line);
int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *next_line, char *buf);
int		ft_strlen(char *str);
char	*ft_get_line(char *next_line);
char	*ft_new_next_line(char *next_line);
void	ft_free(char *next_line, char *buf);
char	*ft_free_and_join(char *next_line, char *buf);

#endif
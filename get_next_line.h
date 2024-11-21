/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoulas <vsoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:30:28 by vsoulas           #+#    #+#             */
/*   Updated: 2024/11/21 10:30:33 by vsoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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
void	read_and_stash(t_list **stash, int fd);
int		ft_found_new_line(t_list *stash);
t_list	*ft_last_node(t_list *stash);
void	ft_add_to_stash(t_list **stash, char *buffer, int bytesread);
void	extract_line(t_list *stash, char **next_line);
void	ft_generate_line(char **next_line, t_list *stash);
void	clean_stash(t_list **stash);
void	ft_fill_last_node(t_list **stash, int i, t_list *last);
void	ft_free_stash(t_list *stash);

#endif
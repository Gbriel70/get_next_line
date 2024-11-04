/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:03:47 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/11/04 11:51:28 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_line
{
	char			*content;
	int				lenght;
	struct s_line	*next;
}	t_line;

char	*get_next_line(int fd);
t_line	*ft_lstnew(char *content);
t_line	*ft_lstlast(t_line *lst);
void	ft_lstadd_back(t_line **lst, t_line *new);
void	ft_lstclear(t_line **lst, void (*del)(void *));
void	*ft_calloc(size_t num, size_t size);

#endif
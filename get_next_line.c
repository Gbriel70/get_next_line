/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:46:59 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/30 15:35:10 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void read_line(t_line **str_cache, int fd);
static int next_line(t_line *str_cache);
static void create_line(t_line *str_cache, char **line);

char *get_next_line(int fd)
{
	static t_line *str_cache;
	char *line;
	
	str_cache = NULL;
	line = NULL;
	if(fd == 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line(&str_cache, fd);
	if (!str_cache)
		return (NULL);
	create_line(str_cache, line);
}

void read_line(t_line **str_cache, int fd)
{
	int		output_r;
	char	*buffer_content;
	t_line	*new_chunk;
	
	output_r = 0;
	while (!next_line(str_cache))
	{
		buffer_content = 0;
		new_chunk = ft_lstnew(buffer_content);
		new_chunk->content = ft_calloc(sizeof(buffer_content), BUFFER_SIZE + 1);
		output_r = read(fd, new_chunk->content, BUFFER_SIZE);
		if (output_r == 0 || output_r == -1)
		{
			free(new_chunk->content);
			free(new_chunk);
			return ;
		}
		new_chunk->content[BUFFER_SIZE] = '\0';
		ft_lstadd_back(str_cache, new_chunk);
	}
}

static int next_line(t_line *str_cache)
{
	int	i;
	
	ft_lstlast(str_cache);
	if (!str_cache || !str_cache->content)
		return (0);
	i = 0;
	while (str_cache->content[i] != '\0')
	{
		if (str_cache->content[i] == '\n')
		{
			str_cache->lenght = i++;
			return (1);
		}
		i++;
	}
	return (0);
}

static void create_line(t_line *str_cache, char **line)
{
	
}

// int	main(void)
// {
// 	int fd = open("teste.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		return (1);
// 	}
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:46:59 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/28 11:50:33 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_buffer(int fd, char *left_str, char *buffer);
static char	*set_line(char *line_buffer);

char	*get_next_line(int fd)
{
	static char	*left_str = NULL;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_str);
		free(buffer);
		left_str = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = line_buffer(fd, left_str, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_str = set_line(line);
	return (line);
}

static char	*line_buffer(int fd, char *left_str, char *buffer)
{
	ssize_t	buffer_read;
	char	*tmp;

	buffer_read = 1;
	while (buffer_read > 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(left_str);
			return (NULL);
		}
		else if (buffer_read == 0)
			break ;
		buffer[buffer_read] = '\0';
		if (!left_str)
			left_str = dup_w("");
		tmp = left_str;
		left_str = str_join(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (str_chr(buffer, '\n'))
			break ;
	}
	return (left_str);
}

static char	*set_line(char *line_buffer)
{
	char	*lef_str;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	lef_str = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*lef_str == 0)
	{
		free(lef_str);
		lef_str = NULL;
	}
	line_buffer[i + 1] = 0;
	return (lef_str);
}

int	main(void)
{
	int fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
	{
		return (1);
	}
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
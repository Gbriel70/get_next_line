/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:48:02 by gcosta-m          #+#    #+#             */
/*   Updated: 2024/10/28 11:49:45 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*dup_w(char *str)
{
	char	*copy;
	char	*i;

	copy = (char *)malloc(ft_strlen(str) + 1);
	if (!copy)
		return (NULL);
	i = copy;
	while (*str)
	{
		*(i++) = *(str++);
	}
	*i = '\0';
	return (copy);
}

char	*str_join(char *src, char *dest)
{
	char	*join;
	char	*result;
	size_t	total_size;

	total_size = ft_strlen(src) + ft_strlen(dest);
	join = (char *)malloc(total_size + 1);
	result = join;
	while (*src)
	{
		*join++ = *src++;
	}
	while (*dest)
	{
		*join++ = *dest++;
	}
	*join = '\0';
	return (result);
}

char	*str_chr(char *src, int c)
{
	while (*src)
	{
		if (*src == (char)c)
			return ((char *)(src + 1));
		src++;
	}
	if ((char)c == '\0')
		return ((char *)(src + 1));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size_s;

	size_s = ft_strlen(s);
	if (start >= size_s)
		return (dup_w(""));
	if (len > size_s - start)
		len = size_s - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

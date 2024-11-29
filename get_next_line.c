/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:07:57 by muidbell          #+#    #+#             */
/*   Updated: 2024/11/28 20:28:48 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *saved)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(saved), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!saved || !ft_strchr(saved, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(saved), NULL);
		buffer[bytes_read] = '\0';
		if (!saved)
			temp = ft_strdup(buffer);
		else
			temp = ft_strjoin(saved, buffer);
		free(saved);
		if (!temp)
			return (free(buffer), NULL);
		saved = temp;
	}
	return (free(buffer), saved);
}

static char	*extract_line(char *content)
{
	int		i;
	char	*line;

	i = 0;
	if (!content[0])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = ft_substr(content, 0, i);
	return (line);
}

static char	*save_remainder(char *content)
{
	int		i;
	char	*remainder;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	if (!content[i])
	{
		free(content);
		return (NULL);
	}
	remainder = ft_strdup(content + i);
	free(content);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(saved),saved = NULL, NULL);
	saved = read_line(fd, saved);
	if (!saved)
		return (NULL);
	line = extract_line(saved);
	if (!line)
	    return (free(saved),saved = NULL,NULL);
	saved = save_remainder(saved);
	return (line);
}

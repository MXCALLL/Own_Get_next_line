/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:07:57 by muidbell          #+#    #+#             */
/*   Updated: 2024/11/27 16:43:00 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remaining;
	char		*buffer;
	char		*temp;
	char		*line;
	char		*detect_new_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 , 0) < 0)
		return (free(remaining), remaining = NULL, NULL);

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	bytes_read = read(fd,buffer,BUFFER_SIZE);

	if (bytes_read == -1)
	{
		// free(remaining);
		// remaining = NULL;
		free(buffer);
		return (NULL);
	}
	else if(bytes_read == 0)
	{
		detect_new_line = ft_strchr(remaining,'\n');
		if (detect_new_line != NULL)
		{
			line = ft_substr(remaining, 0, detect_new_line - remaining + 1);
			temp = ft_strdup(detect_new_line + 1);
			free(remaining);
			remaining = ft_strdup(temp);
			free(temp);
			temp = NULL;
			free(buffer);
			buffer = NULL;
			return (line);
		}
		line = ft_strdup(remaining);
		free(remaining);
		remaining = NULL;
		return (line);
	}

	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		// free(remaining);
		remaining = ft_strjoin(remaining, buffer);
		if (!remaining)
			return (free(remaining),buffer = NULL, NULL);

		detect_new_line = ft_strchr(remaining,'\n');
		if (detect_new_line != NULL)
		{
			line = ft_substr(remaining, 0, detect_new_line - remaining + 1);
			temp = ft_strdup(detect_new_line + 1);
			free(remaining);
			remaining = ft_strdup(temp);
			free(temp);
			temp = NULL;
			free(buffer);
			buffer = NULL;
			return (line);
		}
		bytes_read = read(fd,buffer,BUFFER_SIZE);
	}
	free(buffer);
	buffer = NULL;
	free(remaining);
	remaining = NULL;
 	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluterea <sluterea@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:43:42 by sluterea          #+#    #+#             */
/*   Updated: 2025/01/20 16:43:48 by sluterea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_content(char *content, int fd)
{
	char	*buffer;
	int		bytes;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(content), NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		content = ft_strjoin(content, buffer);
		if (!content)
			return (free(buffer), NULL);
		if (ft_strchr(content, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes == -1)
		return (free(content), free(buffer), NULL);
	return (free(buffer), content);
}

char	*get_line(char	*content)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!content || !content[0])
		return (NULL);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i-- > 0)
		line[i] = content[i];
	return (line);
}

char	*update_content(char *content)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!content[i])
		return (free(content), NULL);
	temp = malloc(ft_strlen(content + ++i) + 1);
	if (!temp)
		return (free(content), NULL);
	j = 0;
	while (content[i])
		temp[j++] = content[i++];
	temp[j] = '\0';
	return (free(content), temp);
}

char	*get_next_line(int fd)
{
	static char	*content[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	content[fd] = get_content(content[fd], fd);
	if (!content[fd])
		return (NULL);
	line = get_line(content[fd]);
	if (!line)
	{
		free(content[fd]);
		content[fd] = NULL;
		return (NULL);
	}
	content[fd] = update_content(content[fd]);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <sramasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:40:25 by sramasam          #+#    #+#             */
/*   Updated: 2025/09/01 20:25:30 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_data(int fd, char *buffer)
{
	char	*temp;
	char	*result;
	int		bytes_read;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(temp);
		return (NULL);
	}
	if (bytes_read == 0)
	{
		free(temp);
		if (buffer && buffer[0] == '\0')
			return (NULL);
		return (buffer);
	}
	temp[bytes_read] = '\0';
	result = ft_join_and_free(buffer, temp);
	return (result);
}

char	*read_and_hold(int fd, char *buffer)
{
	char	*new_buffer;

	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	while (!has_newline(buffer))
	{
		new_buffer = read_data(fd, buffer);
		if (!new_buffer)
		{
			if (buffer[0])
				return (buffer);
			free(buffer);
			return (NULL);
		}
		if (new_buffer == buffer)
			break ;
		buffer = new_buffer;
	}
	return (buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*refresh_buffer(char *buffer)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	remainder = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!remainder)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		remainder[j++] = buffer[i++];
	remainder[j] = '\0';
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_hold(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = refresh_buffer(buffer);
	return (line);
}

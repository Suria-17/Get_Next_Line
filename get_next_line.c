/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <sramasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:40:25 by sramasam          #+#    #+#             */
/*   Updated: 2025/08/24 14:28:07 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_data(int fd, char *buffer)
{
	char	*temp;
	char	*new_buffer;
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
		return (buffer);
	}
	temp[bytes_read] = '\0';
	new_buffer = ft_strjoin(buffer, temp);
	free(buffer);
	free(temp);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

int	has_newline(char *buffer)
{
	if (!buffer)
		return (0);
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
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
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1 + (buffer[len] == '\n')));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[len] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*refresh_buffer(char *buffer)
{
	char	*new_buffer;
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
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
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

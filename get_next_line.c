/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:40:25 by sramasam          #+#    #+#             */
/*   Updated: 2025/07/20 13:40:45 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_and_hold(int fd, char *buffer)
{
    char *temp;
    int bytes_read;

    temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!temp)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(buffer, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, temp, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(temp);
            return (NULL);
        }
        temp[bytes_read] = '\0';
        buffer = ft_strjoin(buffer, temp);
    }
    free(temp);
    return (buffer);
}

static char *extract_line(char *buffer)
{
    int len;
    int i;
    char *line;

    len = 0;
    if (!buffer[len])
        return (NULL);
    while (buffer[len] && buffer[len] != '\n')
        len;
    line = malloc(sizeof(char) * (len + 2));
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}
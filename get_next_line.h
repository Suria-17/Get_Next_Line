/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramasam <sramasam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:15:41 by sramasam          #+#    #+#             */
/*   Updated: 2025/09/01 20:25:04 by sramasam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *s);
int		has_newline(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_join_and_free(char *buffer, char *temp);
char	*get_next_line(int fd);

#endif

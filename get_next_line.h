#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strdup(const char *s);
char *ft_substr(const char *s, unsigned int start, size_t len);

#endif
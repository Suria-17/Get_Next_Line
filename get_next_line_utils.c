#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
        {
            return ((char *)s);
        }
        s++;
    }
    if (c == '\0')
    {
        return ((char *)s);
    }
    return (NULL);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    char *joined;
    int i;
    int j;
    int full_len;

    if (!s1 || !s2)
        return (NULL);

    i = 0;
    j = 0;
    full_len = ft_strlen(s1) + ft_strlen(s2);
    joined = (char *)malloc(sizeof(char) * (full_len + 1));

    if (!joined)
        return (NULL);
    while (s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        joined[i] = s2[j];
        i++;
        j++;
    }
    joined[i] = '\0';
    return (joined);
}

char *ft_strdup(const char *s)
{
    size_t size;
    char *dest;
    size_t i;

    if (!s)
        return (NULL);
    
    size = ft_strlen(s);
    dest = (char *)malloc(sizeof(char) * (size + 1));
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (i < size)
    {
        dest[i] = s[i];
        i++;
    }
    dest[size] = '\0';
    return (dest);
}

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i;
    size_t slen;
    char *sub;

    if (!s)
        return (NULL);

    slen = ft_strlen(s);
    if (start >= slen)
        return (ft_strdup(""));
    if (len > slen - start)
        len = slen - start;
        
    sub = (char *)malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
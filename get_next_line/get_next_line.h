#include <stdio.h>
#ifndef LIBGET_NEXT_LINE
#define LIBGET_NEXT_LINE

char    *get_next_line(int fd);
size_t	ft_strlcpy(char *to, const char *from, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *to, void *from, size_t size);
char	*ft_realloc(char *from, size_t size);
char	*get_next_line(int fd);
int		get_buffer(int fd, char *buffer, int *iter, size_t buffer_size);

#endif


#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>

void	ft_bzero(void *block, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_ascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *to, const void *from, size_t size);
void	*ft_memmove(void *to, void *from, size_t size);
void	*ft_memset(void *block, int c, size_t size);
char	*ft_strchr(const char *string, int c);
size_t	ft_strlcat(char *to, const char *from, size_t size);
size_t	ft_strlcpy(char *to, const char *from, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
char	*ft_strchr(const char *string, int c);
char	*ft_strrchr(const char *string, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strnstr(const char *big, const char *little, size_t size);
int		ft_memcmp(const char *a1, const char *a2, size_t size);
void	*ft_memchr(const void *block, int c, size_t size);
int		ft_atoi(const char *string);
void	*ft_calloc(size_t count, size_t eltsize);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
#endif
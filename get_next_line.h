#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>

//// debug 
//#include <fcntl.h>
//#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *string, int searchedChar);
void	*ft_memcpy( void *destination, const void *source, size_t size );
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(char *src, char* end);
char    *get_global_buffer(int fd);
char    *get_next_line(int fd);

#endif
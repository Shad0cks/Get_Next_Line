#include "get_next_line.h"

char    *ft_strdup(char *src, char* end)
{
	char	*cped;
	int	i;

	i = 0;
    (void)end;
	cped = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cped == NULL)
		return (NULL);
	while (src != end)
	{
		cped[i] = *src;
		i++;
        src++;
	}
	cped[i] = '\0';
	return (cped);
}

char *get_global_buffer(int fd)
{
    char buffer[BUFFER_SIZE];
    char *global_buffer;
    int ret;

    global_buffer = NULL;
    ret = read(fd, buffer, BUFFER_SIZE);
    while(ret != 0)
    {
        if (!global_buffer)
             global_buffer = ft_strjoin("", buffer);
        else
            global_buffer = ft_strjoin(global_buffer, buffer);
        ret = read(fd, buffer, BUFFER_SIZE);
    }
    buffer[ret] = '\0';
    return (global_buffer);
}

char *get_next_line(int fd)
{
    static char *global_buffer;
    static int line;
    char *line_buffer;
    char    *start;
    int size_line;
    
    size_line = 0;
    if (!line || !global_buffer)
    {
        line = 0;
        global_buffer =  get_global_buffer(fd);
    }
    start = global_buffer;
    if  (ft_strchr(global_buffer, '\n') != NULL)
    {
        line_buffer = ft_strdup(start, ft_strchr(global_buffer, '\n') + 1);
        global_buffer = ft_strchr(global_buffer, '\n') + 1;
    }
    else
    {
        line_buffer = ft_strdup(start, ft_strchr(global_buffer, '\0'));
        free(global_buffer);
    }
    line++;
    return (line_buffer);
}

/*
int main(void)
{
    int fd = open("/Users/pierre-louis/Documents/C/Project_GNL/GNL/test.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("ERROR FILE NOT FOUND \n");
        return (-1);
    }
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));

    close(fd);
    return (0);
}
*/
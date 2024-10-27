#include "get_next_line.h"

#include "get_next_line.h"

static char *line_buffer(int fd, char *left_str, char *buffer);

char    *get_next_line(int fd)
{
    static char *left_str = NULL;
    char *buffer;
    char *line;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(left_str);
        free(buffer);
        left_str = NULL;
        buffer = NULL;
        return(NULL);
    }
    if(!buffer)
        return NULL;
    line  = line_buffer(fd, left_str, buffer);

    free(buffer);
    if(!line)
        return NULL;
    left_str = set_line(line);
    return(line);
}

static char *line_buffer(int fd, char *left_str, char *buffer)
{

}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        fprintf(stderr, "uso: %s <teste.txt>\n", av[0]);
        return 1;
    }

    int fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        return 1;
    }
    char *line;

    while((line = get_next_line(fd) != NULL))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
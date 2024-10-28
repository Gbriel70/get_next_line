#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100000000000000
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>

char *get_next_line(int fd);
char *dup_w(char *str);
char *str_join(char *src, char *dest);
char *str_chr(char *src, int c);
size_t ft_strlen(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);


#endif
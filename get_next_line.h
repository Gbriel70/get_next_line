#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);
char *dup_w(char *str);
char *str_join(char *src, char *dest);
char str_chr(char *src, char c);
size_t _strlen(char *str);
char *_substr(char const *s, unsigned int start, size_t len);


#endif
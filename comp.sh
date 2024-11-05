normal="get_next_line.c get_next_line_utils.c"

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 $normal && valgrind --tool=memcheck -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./a.out | cat -e
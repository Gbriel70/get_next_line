bonus="get_next_line_bonus.c get_next_line_utils_bonus.c"

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 $bonus && valgrind --tool=memcheck -q --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./a.out | cat -e
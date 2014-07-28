gcc -Wall -Werror -Wextra -I libft/includes/ -c asup_main.c
gcc -Wall -Werror -Wextra -I libft/includes/ -c get_next_line.c
gcc -o exec_gnt_test get_next_line.o asup_main.o -L libft/ -lft

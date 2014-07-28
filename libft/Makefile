.PONY: clean name all

NAME =		libft.a

SRC =		ft_strlen.c ft_strcpy.c ft_strcat.c\
			ft_strchr.c ft_strlen_chr.c ft_strncat.c\
			ft_strncpy.c

OBJ =		$(SRC:.c=.o)

FLAGS =		-Wall -Werror -Wextra

CC =		gcc

all:		name

name:
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
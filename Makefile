NAME 	= 	push_swap
CC 		= 	cc
CFLAGS 	= 	-I include/ -Wall -Werror -Wextra
SRC		= 	utils2.c		\
			operations2.c	\
			sort_five.c		\
			parse_utils2.c	\
			checkErr.c		\
			sort_more.c		\
			utils.c			\
			parse_utils1.c	\
			push_swap.c		\
			utils_stack.c	\
			sort_three.c	\
			parsing.c		\
			operations.c

LIBS	=	libft/libft.a

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $^ $(LIBS) -o $@ -g

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
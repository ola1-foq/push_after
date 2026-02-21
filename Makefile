CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRC= main.c \
	utils.c \
	radix.c \
	rotate.c \
	swap_push.c \
	sort_small.c \
	reverse_rotate.c \
	helper_small.c\
	checking_fun.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)  

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	@rm -f $(OBJ)
fclean:clean
	@rm -f $(NAME)
re:fclean all

.PHONY: all clean fclean re
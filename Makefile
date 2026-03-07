NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra 

RM		= rm -f

INC		= -I.

SRC		= push_swap.c \
		  1.stack/stack_init.c \
		  1.stack/stack_push_pop.c \
		  1.stack/stack_free.c \
		  1.stack/stack_utils.c \
		  2.command/ops_base.c \
		  2.command/cmd_push.c \
		  2.command/cmd_swap.c \
		  2.command/cmd_rotate.c \
		  2.command/cmd_rev_rotate.c \
		  3.parsing/ft_split_utils.c \
		  3.parsing/ft_split.c \
		  3.parsing/parsing_utils.c \
		  3.parsing/parsing.c \
		  4.sort/sort_simple.c \
		  4.sort/turkish.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
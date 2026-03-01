NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

INC		= -I.

SRC		= push_swap.c \
		  1.stack/stack_init.c \
		  1.stack/stack_push_pop.c \
		  1.stack/stack_free.c \
		  1.stack/stack_utils.c \
		  2.commands/ops_base.c \
		  2.commands/cmd_push.c \
		  2.commands/cmd_swap.c \
		  2.commands/ops_rotate.c \
		  2.commands/ops_rev_rotate.c \
		  3.parsing/ft_split_utils.c \
		  3.parsing/ft_split.c \
		  3.parsing/parsing_utils.c \
		  3.parsing/parsing.c

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
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = command.c \
		few_arg.c \
		index.c \
		init_exit.c \
		input.c \
		linked_list.c \
		main.c \
		operation.c \
		search_a.c \
		search_b.c \
		search_utils.c \
		sort.c \
		stack.c \
		subproblem_a.c \
		subproblem_b.c \
		utils.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

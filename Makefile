NAME = push_swap
BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_INCLUDES = -I LIBFT/

LIBFT = LIBFT/libft.a

SRCS = main.c \
		stack.c \
		arg_check.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		push.c \
		sort_three.c \
		utils.c \
		sort.c \
		bonus.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

all: $(NAME)

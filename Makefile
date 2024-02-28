TARGET = push_swap

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

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -o $(TARGET) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

all: $(TARGET)`

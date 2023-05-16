NAME    = server client

HEADER  = minitalk.h

SRCS    = ft_server.c ft_client.c

OBJS    = $(SRCS:.c=.o)

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

LIBFT   = libft/libft.a

LIBFT_DIR = libft


all: $(NAME)


server: $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $@ $< -L $(LIBFT_DIR) -lft

client: $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $@ $< -L $(LIBFT_DIR) -lft

clean:
	@rm -f $(OBJS)
	@make -s clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re server client

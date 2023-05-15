NAME    = server client

HEADER  = minitalk.h

SERVER_SRCS = Server/ft_server.c
CLIENT_SRCS = Cliente/ft_cliente.c

SERVER_OBJS = $(SERVER_SRCS:Server/%.c=Server/%.o)
CLIENT_OBJS = $(CLIENT_SRCS:Cliente/%.c=Cliente/%.o)

CC      = gcc

CFLAGS  = -g -ggdb
RM      = rm -rf

LIBFT   = libft/libft.a

LIBFT_DIR = libft

.PHONY: all clean fclean re server client

all: $(NAME)

.SILENT: $(SERVER_OBJS) $(CLIENT_OBJS)

server: $(SERVER_OBJS)
	@make -C $(LIBFT_DIR) --silent
	@$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

client: $(CLIENT_OBJS)
	@make -C $(LIBFT_DIR) --silent
	@$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

clean:
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@make -s clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)

re: fclean all
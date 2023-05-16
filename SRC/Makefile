CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft
INCLUDES = -I./libft

all: client server

client: ft_client.c mini_talk.h libft/libft.a
	@$(CC) $(CFLAGS) $(INCLUDES) -o client ft_client.c $(LDFLAGS)

server: ft_server.c mini_talk.h libft/libft.a
	@$(CC) $(CFLAGS) $(INCLUDES) -o server ft_server.c $(LDFLAGS)

libft/libft.a:
	@make -C libft

clean:
	@rm -f ft_client ft_server
	@make -C libft clean

fclean: clean
	@make -C libft fclean

re: fclean all
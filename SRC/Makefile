NAME	= servertest

HEADER	= minitalk.h

SRCS 	=  $(wildcard Server/*c)

OBJS	= $(SRCS:c=o)

CC		= gcc

CFLAGS	= -g -ggdb
RM		= rm -f

LIBFT 	= libft/libft.a

LIBFT_DIR = libft

all: $(NAME)

.SILENT: $(OBJS)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) --silent
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

clean:
	@rm -f $(OBJS)
	@make -s clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_DIR)
run:
	make re && clear && ./servertest

re: fclean all
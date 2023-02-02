NAME	= so_long.a
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror
LIBFT	= libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

SRCS =	./tools/ft_messages_error.c\
		./tools/movement.c\
		./tools/ft_strjoin.c\
		./tools/keys.c\
		so_long.c\
		./get_next_line/get_next_line_utils.c\
		./get_next_line/get_next_line.c\
		./tools/check_map.c\

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT) $(FT_PRINTF)
	@$(CC) libft/libft.a -lmlx -framework OpenGL -framework AppKit  $^ -o $@
	@echo "\033[4;35m                                                               \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "\033[4;35m By: mayache \033[0m"
$(LIBFT):
	@make -C libft
	@make -C libft bonus

$(FT_PRINTF):
	@make -C ft_printf

clean:
	@rm -f $(OBJS)
	@make -C libft clean
	@make -C ft_printf clean
	@echo "clean so_long"

fclean: clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@rm -f $(NAME)
	@echo "fclean so_long"

re: fclean all
	@echo "re so_long"

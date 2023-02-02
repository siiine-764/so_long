NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = ft_printf.h

SRC = ft_printf.c ft_putchr.c ft_putstr.c ft_putnbr.c\
ft_print_hex.c ft_print_pointer.c ft_unsigned_int.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(DEPS)
	@$(CC) -o $@ -c $< $(CFLAGS)

all: $(NAME)

clean: 
	@rm -f *.o
	@echo "clean ft_printf"

fclean: clean 
	@rm -f *.a
	@echo "fclean ft_printf"


re: fclean $(NAME)

.PHONY: clean fclean re all
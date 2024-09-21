

NAME = libftprintf.a
HEADER_FILE = printf.h
FILES = ft_printf.c \
        base.c \
        print_format.c \
        print_nbr.c \
        print_str.c

CFLAGS = -Wextra -Wall -Werror
OFILES = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar -rs $(NAME) $(OFILES)

%.o: %.c $(HEADER_FILE)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
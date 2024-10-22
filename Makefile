# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antimit <antimit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 16:31:17 by antimit           #+#    #+#              #
#    Updated: 2024/10/22 16:52:08 by antimit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



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
	ar -rcs $(NAME) $(OFILES)

%.o: %.c $(HEADER_FILE)
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

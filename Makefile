# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/27 13:30:55 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/03/08 18:08:17 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src
OBJDIR = obj

SOURCES = $(SRC)/ft_printf.c \
          $(SRC)/default_flags.c \
          $(SRC)/parse_conv.c \
          $(SRC)/print_part.c \
          $(SRC)/field_width.c \
          $(SRC)/conv/c_conv.c \
          $(SRC)/conv/s_conv.c \
          $(SRC)/conv/i_conv.c \
          $(SRC)/conv/u_conv.c \
          $(SRC)/conv/x_conv.c \
          $(SRC)/conv/p_conv.c
OBJECTS = $(patsubst $(SRC)/%,$(OBJDIR)/%, $(SOURCES:c=o))

.PHONY = all clean fclean re test libft

all: $(NAME)

debug: test.c re
	gcc $(CFLAGS) -g test.c $(NAME)
	# @echo ./a.out
	# @echo -------------
	# @./a.out
	# @rm a.out

$(NAME): $(OBJECTS) libft
	cp lib/libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRC)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C lib/libft bonus

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all

$(OBJDIR):
	mkdir -p $(OBJDIR)

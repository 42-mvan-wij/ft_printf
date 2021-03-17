# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/27 13:30:55 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/03/17 16:05:04 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = lib/libft/libft.a

CC = gcc
CFLAGS =
#-Wall -Wextra -Werror
ifdef DEBUG
CFLAGS += -g
endif

SRC = src
OBJDIR = obj

SOURCES = $(SRC)/ft_printf.c \
          $(SRC)/default_flags.c \
          $(SRC)/parse_conv.c \
          $(SRC)/print_part.c \
          $(SRC)/field_width.c \
          $(SRC)/conv/pct_conv.c \
          $(SRC)/conv/c_conv.c \
          $(SRC)/conv/s_conv.c \
          $(SRC)/conv/i_conv.c \
          $(SRC)/conv/u_conv.c \
          $(SRC)/conv/x_conv.c \
          $(SRC)/conv/p_conv.c \
          $(SRC)/conv/n_conv.c \
          $(SRC)/precision.c
OBJECTS = $(patsubst $(SRC)/%,$(OBJDIR)/%, $(SOURCES:c=o))

.PHONY: all clean fclean re test debug profile $(LIBFT)

all: $(NAME)

test: $(SOURCES) test.c $(LIBFT)
	gcc $(CFLAGS) $(SOURCES) test.c $(LIBFT)
	@echo ./a.out
	@echo ------------
	@./a.out

debug: test.c
	$(MAKE) re DEBUG=1
	gcc $(CFLAGS) -g test.c $(NAME)
	@# @echo ./a.out
	@# @echo -------------
	@# @./a.out
	@# @rm a.out

profile: debug
	valgrind -q --tool=callgrind --callgrind-out-file=/tmp/callgrind.out ./a.out
	gprof2dot --format=callgrind -o/tmp/out.dot /tmp/callgrind.out
	dot -Gdpi=400 -Tpng /tmp/out.dot -o profile.png

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -crs $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
ifdef DEBUG
	$(MAKE) -C lib/libft debug bonus
else
	$(MAKE) -C lib/libft bonus
endif

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C lib/libft clean

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	$(MAKE) -C lib/libft fclean

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-wij <mvan-wij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/27 13:30:55 by mvan-wij      #+#    #+#                  #
#    Updated: 2021/02/27 14:12:22 by mvan-wij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = src
OBJDIR = obj

SOURCES = $(SRC)/ft_printf.c
OBJECTS = $(patsubst $(SRC)/%,$(OBJDIR)/%, $(SOURCES:c=o))

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -crs $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRC)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)

fclean: clean
	rm -r $(OBJDIR)
	rm $(NAME)

re: fclean all

$(OBJDIR):
	mkdir -p $(OBJDIR)

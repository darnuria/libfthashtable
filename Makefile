# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviala <aviala@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 20:00:55 by aviala            #+#    #+#              #
#    Updated: 2013/12/15 06:55:10 by aviala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hotrace
DEBUG = yes
LD = $(CC)
SRCDIR = ./sources
OBJDIR = ./objects
INCDIR = -I./includes

ifeq ($(DEBUG),yes)
	CC = clang
	CFLAGS = -fstack-protector-all -ansi -Wshadow -Wall -Werror -Wextra \
		-Wunreachable-code -Wstack-protector -pedantic-errors \
		-Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes \
		-Wwrite-strings -Wunreachable-code -pedantic \
		-Wunknown-pragmas -Wdeclaration-after-statement \
		-Wold-style-definition -Wmissing-field-initializers \
		-Winline -g -W
else
	CC = gcc
	CFLAGS= -Wall -Wextra -Werror -O3
endif

LDFLAGS =
SRC = main.c \
		hastable.c \
		ft_murmurhash.c \
		ft_utils.c \
		ft_string.c
OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_PREF)
	$(LD) -o $@ $^ $(LDFLAGS) $(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INCDIR)

clean:
	@rm -f $(OBJS_PREF)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: clean fclean re all

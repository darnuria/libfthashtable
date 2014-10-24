# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviala <aviala@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 20:00:55 by aviala            #+#    #+#              #
#    Updated: 2013/12/15 12:56:34 by aviala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libnaive_hashtable
SRCDIR = ./sources
OBJDIR = ./objects
LDFLAGS =
SRC = hashtable.c \
	hashtable2.c \
	get_next_line.c \
	ft_murmurhash.c \
	ft_string.c \
	ft_string2.c
INCDIR = -I./includes
CFLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors

ifeq ($(DEBUG),yes)
	CC = clang
	CFLAGS += -ggdb3 -fstack-protector-all -Wshadow -Wunreachable-code \
		-Wstack-protector -pedantic-errors -O0 -W -Wundef -fno-common \
		-Wfatal-errors -Wstrict-prototypes -Wmissing-prototypes -pedantic \
		-Wwrite-strings -Wunknown-pragmas -Wdeclaration-after-statement\
		-Wold-style-definition -Wmissing-field-initializers -Wfloat-equal\
		-Wpointer-arith -Wnested-externs -Wstrict-overflow=5 -fno-common\
		-Wno-missing-field-initializers -Wswitch-default -Wswitch-enum \
		-Wbad-function-cast -Wredundant-decls -fno-omit-frame-pointer
		-std=c89
else
	CC = gcc
	CFLAGS += -O3
endif

OBJS = $(SRC:.c=.o)
OBJS_PREF = $(addprefix $(OBJDIR)/, $(OBJS))
LD = $(CC)

all: $(NAME)

$(NAME): $(OBJS_PREF)
	@echo "Linking $@."
	@ar rcs $@.a $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $@ into $<"
	@$(CC) $(CFLAGS) $(INCDIR) -o $@ -c $<
clean:
	@rm -f $(OBJS_PREF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

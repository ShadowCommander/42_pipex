# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/10/20 11:25:13 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
FILENAMES := main
LIBS := ft
LIBNAMES := libft.a
LIBFULL := libft/libft.a #$(addprefix $(LIBDIR)/,$(LIBNAME))
LIB_INCLUDES := $(LIBS)
LIBDIRS := libft
HEADERDIRS := . $(LIBDIRS) bonus

OBJ := $(addsuffix .o,$(FILENAMES))

CC := clang
HEADERFLAGS := $(addprefix -I,$(HEADERDIRS))
LIBFLAGS := $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIB_INCLUDES))
OFLAGS := $(HEADERFLAGS)
CCFLAGS := -Wall -Werror -Wextra $(HEADERFLAGS) $(LIBFLAGS)
MODE =

all: $(NAME)

debug: CCFLAGS += -g
debug: CFLAGS += -g
debug: OFLAGS += -g
debug: MODE = debug
debug: cleanobj $(NAME) 

leaks: CCFLAGS += -fsanitize=address
leaks: cleanobj $(NAME) 

$(NAME): $(OBJ) $(LIBFULL)
	$(CC) $(notdir $(OBJ)) $(CCFLAGS) -o $@

$(LIBFULL):
	$(MAKE) -C libft $(MODE)

%.o: %.c
	$(CC) $(OFLAGS) -c $<

test: $(NAME)
	@-/bin/rm -f out.txt
	@echo "Run $(NAME)"
	./$(NAME) ~/42/pipex/test/in.txt /bin/cat /bin/cat ~/42/pipex/test/out.txt
	@echo "\nCheck $(NAME) permissions"
	@/bin/ls -l ~/42/pipex/test/out.txt
	@echo "\nContents:"
	@cat ~/42/pipex/test/out.txt

clean:
	/bin/rm -f $(NAME)

fclean: clean
	/bin/rm -f $(OBJ)
	$(MAKE) -C libft clean

re: fclean all

cleanobj:
	/bin/rm -f $(OBJ)

.PHONY: all env debug test clean fclean cleanobj re mlx

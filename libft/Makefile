# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/10/21 11:17:09 by jtong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRC := $(wildcard *.c)
HEADERS := .
FILES := $(SRC)
OBJ := $(notdir $(FILES:.c=.o))
CC := clang
CCFLAGS := -Werror -Wall -Wextra ${CFLAGS}

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	$(CC) $(CCFLAGS) -c $(FILES) -I $(HEADERS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) libft.h.gch

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/10/18 11:48:25 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRC := ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strlcpy.c ft_lstsize.c \
	ft_printbits.c ft_wordcount.c ft_itoa_base.c ft_isspace.c ft_strtol.c \
	ft_isupper.c ft_islower.c ft_ulltoa_base.c ft_strndup.c ft_isnum.c
#LIST_FILES
SRC += $(addprefix list/, \
	ft_listadd.c ft_listclear.c ft_listfree.c ft_listlop.c \
	ft_listnew.c ft_listnode.c ft_listpop.c ft_listpush.c ft_listrm.c \
	ft_listsort.c ft_listsrt.c ft_listfind.c)
HEADERS := . #list/libft_list.h
FILES := $(SRC) #$(addprefix list/, $(LIST_FILES))
OBJ := $(notdir $(FILES:.c=.o))
CC := clang
CFLAGS := -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	$(CC) $(CFLAGS) -c $(FILES) -I $(HEADERS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) libft.h.gch

re: fclean all

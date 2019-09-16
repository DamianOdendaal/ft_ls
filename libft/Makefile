# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 12:58:49 by dodendaa          #+#    #+#              #
#    Updated: 2019/09/12 13:10:41 by dodendaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -I. -c

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_iswhitespace.c ft_wordcount.c \
	   ft_strndup.c ft_intlen.c ft_space.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c libft.h
	@echo "\033[1;36;m[Compiling $<] \t\033[0m"
	@gcc -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Library Compiled"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, re, fclean, clean
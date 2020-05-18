# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodendaa <dodendaa@student.wethinkcode.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 13:32:48 by dodendaa          #+#    #+#              #
#    Updated: 2020/05/18 16:13:59 by dodendaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT_DIR = libft
LIBFT_CFILES = libft/%.c
SRCS_D = srcs
OBJS_D = objs
LIBFT_LIB = -L $(LIBFT_DIR)/ -lft
LIB = libft/libft.a
HEADERS = -I./includes -I./$(LIBFT_DIR)
CFLAGS = -Wall -Werror -Wextra $(HEADERS)
CC = gcc -g

SOURCES = convert.c errors.c flags.c ft_ls.c time.c\
			output.c lists.c recursion.c sorting.c\
			long_printing.c long_formatting.c extra.c ft_merge.c\
			compare.c \

OBJECTS = $(addprefix $(OBJS_D)/,$(SOURCES:.c=.o))

$(OBJS_D)/%.o: $(SRCS_D)/%.c libft/libft.h includes/*
	@echo "[Compiling $<] "
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): dir $(OBJECTS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIB) 
	@echo "ft_ls ready to use! "

all: dir $(NAME)

dir:
	@mkdir -p $(OBJS_D)

clean:
	@echo "\033[1;34;m[Cleaning $<] \t\033[0m"
	@rm -rf $(OBJECTS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[1;34;m[Force $<] \t\033[0m"
	@rm -rf $(OBJS_D)
	@rm -rf $(NAME)

re: fclean clean all
	
.PHONY: fclean clean all re
	

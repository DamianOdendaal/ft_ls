# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 13:32:48 by dodendaa          #+#    #+#              #
#    Updated: 2019/09/12 15:10:18 by dodendaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT_DIR = libft
LIBFT_CFILES = libft/%.c
SRCS_D = srcs
OBJS_D = objs
LIBFT_LIB = -L $(LIBFT_DIR) -lft
HEADERS = -I./includes -I./$(LIBFT_DIR)
CFLAGS = -Wall -Werror -Wextra $(HEADERS)
CC = gcc -g
SOURCES = main.c ft_check_dirs.c  ft_currdir.c  ft_errors.c  ft_flags.c \
		ft_permissions.c ft_sort.c ft_getpwuid.c ft_long_print.c\

OBJECTS = $(addprefix $(OBJS_D)/,$(SOURCES:.c=.o))

$(OBJS_D)/%.o: $(SRCS_D)/%.c libft/libft.h includes/*
	@echo "\033[1;35;m[Compiling $<] \t\033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): dir $(OBJECTS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_LIB) $(HEADERS)
	@echo "\033[1;32;mft_ls ready to use! \t\033[0m"

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
	
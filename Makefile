# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodendaa <dodendaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 13:32:48 by dodendaa          #+#    #+#              #
#    Updated: 2019/09/11 16:35:06 by dodendaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT_DIR = libft
DEPS = libft/libft.a
SRCS_D = srcs
OBJS_D = objs
LIBFT_LIB = -L $(LIBFT_DIR) -lft
HEADERS = -I./includes -I./$(LIBFT_DIR)
CFLAGS = -Wall -Werror -Wextra $(HEADERS)
CC = gcc
SOURCES = main.c ft_check_dirs.c  ft_currdir.c  ft_errors.c  ft_flags.c \
		ft_permissions.c ft_sort.c ft_getpwuid.c\

OBJECTS = $(addprefix $(OBJS_D)/,$(SOURCES:.c=.o))

$(OBJS_D)/%.o: $(SRCS_D)/%.c libft/libft.h includes/*
	@echo "\033[1;35;m[Compiling $<] \t\033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): dir $(OBJECTS)
	@make -C $(LIBFT_DIR)
	@gcc $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT_LIB) $(HEADERS)

all: dir $(NAME)

dir:
	@mkdir -p $(OBJS_D)

clean:
	@$(CLEAN_PRINT)
	@rm -rf $(OBJECTS)

fclean: clean
	@$(FORCE_CLEAN)
	@rm -rf $(OBJS_D)
	@rm -rf $(NAME)

re: fclean clean all
	
.PHONY: fclean clean all re
	
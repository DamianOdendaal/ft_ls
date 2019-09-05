# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 13:32:48 by dodendaa          #+#    #+#              #
#    Updated: 2019/09/03 13:47:18 by dodendaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls
DEPS=libft.a
LIBFT_DIR=libft
INCLUDES=$(LIBFT_DIR)
REL_DEPS=$(DEPS:%=$(LIBFT_DIR)/%)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -I . -Ofast
CFILES=	 main.c ft_check_dirs.c  ft_currdir.c  ft_dash1.c  ft_errors.c  ft_flags.c  ft_long_print.c \
		

OBJ=$(CFILES:%.c=build/%.o)

$(NAME): $(OBJ) $(REL_DEPS)
	@gcc $(CFLAGS) $(OBJ) $(REL_DEPS) -o $(NAME)

$(REL_DEPS):
	@make -C $(dir $@)

build/%.o: %.c
	@mkdir -p build
	@$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME);

clean fclean re::
	@for file in $(dir $(REL_DEPS)) ; do $(MAKE) -C $$file $@ ; done

clean::
	@rm -rf build/

fclean::
	@rm -rf $(NAME)

re:: fclean all

.PHONY: clean fclean re all $(REL_DEPS)

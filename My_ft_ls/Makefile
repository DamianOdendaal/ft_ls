# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dodendaa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/17 13:32:48 by dodendaa          #+#    #+#              #
#    Updated: 2019/07/17 13:57:08 by dodendaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# CFLAGS = -Wall -Werror -Wextra -I.

# NAME = a.out

# LIBFT = make -C libft re

# SRCS = ft_check_dirs.c ft_currdir.c ft_dash1.c ft_errors.c ft_flags.c\
# 		ft_long_print.c ft_ls.c libft/libft.a


# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME):
# 	gcc $(CFLAGS) $(SRCS)
# 	ar rc $(NAME) $(OBJS)
# 	ranlib $(NAME)

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all, re, fclean, clean


NAME = ft_ls
DEPS = libft.a
LIBFT_DIR = libft
INCLUDES = $(LIBFT_DIR)/includes
REL_DEPS = $(DEPS:%=$(LIBFT_DIR)/%)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES) -I . -Ofast
CFILES = ft_check_dirs.c ft_currdir.c ft_dash1.c ft_errors.c ft_flags.c\
		ft_long_print.c ft_ls.c\

OBJ = $(CFILES:%.c=build/%.o)

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

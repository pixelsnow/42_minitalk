# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 16:28:38 by vvagapov          #+#    #+#              #
#    Updated: 2022/12/23 21:31:10 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_print_char.c \
		ft_print_str.c \
		ft_print_int.c \
		ft_print_unsigned.c \
		ft_print_hex.c \
		ft_print_ptr.c

OBJ = $(SRC:%.c=%.o)

LIBFT_DIR = libft

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $@
	@ar -ruvcs $@ $^

%.o: %.c
	@cc $(FLAGS) -c -o $@ $^

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

test: all
	@cc testing/main.c $(NAME)

testclean: fclean
	@rm -f a.out

.PHONY: all clean fclean re test testclean
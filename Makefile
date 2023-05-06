# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 21:58:02 by vvagapov          #+#    #+#              #
#    Updated: 2023/05/06 23:56:32 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SERVERNAME = server

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

OBJ_CLIENT = $(SRC:%.c=%.o)
OBJ_SERVER = $(SRC:%.c=%.o)
OBJ_CLIENT_BONUS= $(SRC:%.c=%.o)
OBJ_SERVER_BONUS = $(SRC:%.c=%.o)

LIBFTPRINTF_DIR = libftprintf

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(SERVERNAME)

$(LIBFTPRINTF): 
	$(MAKE) -C libftprintf
	
$(NAME): $(OBJ_CLIENT)
	$(MAKE) -C libftprintf
	@cc $(NAME) $(FLAGS) $(OBJ_CLIENT) libftprintf/libftprintf.a -o 

$(SERVERNAME): $(OBJ_SERVER)
	$(MAKE) -C libftprintf
	@cc $(FLAGS) $(OBJ_SERVER) libftprintf/libftprintf.a -o $(SERVERNAME)

%.o: %.c
	@cc $(FLAGS) -c -o $@ $^

clean:
	$(MAKE) clean -C libftprintf
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(MAKE) fclean -C libftprintf
	@rm -f $(NAME) $(SERVERNAME)

re: fclean all

.PHONY: all clean fclean re
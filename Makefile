# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 21:58:02 by vvagapov          #+#    #+#              #
#    Updated: 2023/05/20 17:35:43 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SERVERNAME = server

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)
OBJ_CLIENT_BONUS= $(SRC_CLIENT_BONUS:%.c=%.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)

LIBFTPRINTF = libftprintf/libftprintf.a
LIBFTPRINTF_DIR = libftprintf

FLAGS = -Wall -Wextra -Werror
INC = -I. -I$(LIBFTPRINTF_DIR)

all: $(LIBFTPRINTF) $(NAME) $(SERVERNAME)

$(LIBFTPRINTF): 
	make -C $(LIBFTPRINTF_DIR)
	
$(NAME): $(OBJ_CLIENT) 
	cc $(OBJ_CLIENT) $(INC) $(LIBFTPRINTF) -o $(NAME)

$(SERVERNAME): $(OBJ_SERVER) 
	cc $(OBJ_SERVER) $(INC) $(LIBFTPRINTF) -o $(SERVERNAME)

%.o: %.c
	cc -c $(FLAGS) $^

clean:
	make clean -C $(LIBFTPRINTF_DIR)
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SERVER)

fclean: clean
	make fclean -C $(LIBFTPRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
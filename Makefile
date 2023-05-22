# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 21:58:02 by vvagapov          #+#    #+#              #
#    Updated: 2023/05/22 14:46:51 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
SERVERNAME = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

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

bonus: $(LIBFTPRINTF) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	cc $(OBJ_CLIENT_BONUS) $(INC) $(LIBFTPRINTF) -o $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS)
	cc $(OBJ_SERVER_BONUS) $(INC) $(LIBFTPRINTF) -o $(SERVER_BONUS)

%.o: %.c
	cc -c $(FLAGS) $^

clean:
	make clean -C $(LIBFTPRINTF_DIR)
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT_BONUS)
	rm -f $(OBJ_SERVER_BONUS)

fclean: clean
	make fclean -C $(LIBFTPRINTF_DIR)
	rm -f $(NAME)
	rm -f $(SERVERNAME)
	rm -f $(CLIENT_BONUS)
	rm -f $(SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re

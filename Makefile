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

OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)
OBJ_CLIENT_BONUS= $(SRC_CLIENT_BONUS:%.c=%.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:%.c=%.o)

LIBFTPRINTF = libftprintf.a
LIBFTPRINTF_DIR = libftprintf

FLAGS = -Wall -Wextra -Werror
INC = -I. -I$(LIBFTPRINTF_DIR)

all: $(LIBFTPRINTF) $(NAME) $(SERVERNAME)

$(LIBFTPRINTF): 
	$(MAKE) -C $(LIBFTPRINTF_DIR)
	
$(NAME): $(OBJ_CLIENT) 
	@cc $(OBJ_CLIENT) $(INC) -o $(NAME) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF)

$(SERVERNAME): $(OBJ_SERVER) 
	@cc $(OBJ_SERVER) $(INC) -o $(SERVERNAME) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF)

%.o: %.c
	@cc -c $(FLAGS) $^

clean:
	$(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@rm -f $(OBJ_CLIENT)
	@rm -f $(OBJ_SERVER)

fclean: clean
	$(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@rm -f $(NAME)
	@rm -f $(SERVERNAME)

re: fclean all

.PHONY: all clean fclean re
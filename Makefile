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

LIBFTPRINTF = libftprintf.a
LIBFTPRINTF_DIR = libftprintf

FLAGS = -Wall -Wextra -Werror
INC = -I. -I$(LIBFTPRINTF_DIR)

all: $(LIBFTPRINTF) $(NAME) $(SERVERNAME)

$(LIBFTPRINTF): 
	$(MAKE) -C $(LIBFTPRINTF_DIR)

	
$(NAME): $(OBJ_CLIENT) 
	@cc $(INC) -o $(NAME) $(OBJ_CLIENT) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF)

$(SERVERNAME): $(OBJ_SERVER) 
	@cc $(INC) -c -o $(SERVERNAME) $(OBJ_SERVER) $(LIBFTPRINTF_DIR)/$(LIBFTPRINTF)

%.o: %.c
	@cc -c $(FLAGS) -o $@ $^

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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 20:11:58 by vvagapov          #+#    #+#              #
#    Updated: 2023/05/20 18:21:48 by vvagapov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS_SRC = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:%.c=%.o}

BONUS_OBJ = ${BONUS_SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJ}
	@ar -ruvcs $@ $^

bonus: .bonus_flag

.bonus_flag: ${BONUS_OBJ}
	@ar -ruvcs ${NAME} ${BONUS_OBJ}
	-@touch .bonus_flag

%.o: %.c
	@cc ${FLAGS} -c -o $@ $^
	
clean:
	@rm -f ${OBJ} ${BONUS_OBJ}
	-@rm -f .bonus_flag

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT:
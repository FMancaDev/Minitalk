# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 17:43:44 by fomanca           #+#    #+#              #
#    Updated: 2025/12/18 16:58:09 by fomanca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

FT_PRINTF = ./ft_printf/libftprintf.a
SRCS_DIR = srcs/

UTILS = $(SRCS_DIR)ft_atoi.c $(SRCS_DIR)ft_isdigit.c
SRC_SERVER = $(SRCS_DIR)server.c $(UTILS)
SRC_CLIENT = $(SRCS_DIR)client.c $(UTILS)

all: $(FT_PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

$(FT_PRINTF):
	@make -C ./ft_printf

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(FT_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(FT_PRINTF) -o $(NAME_CLIENT)

clean:
	@make clean -C ./ft_printf

fclean: clean
	@make fclean -C ./ft_printf
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re

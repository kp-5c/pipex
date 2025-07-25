# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 10:00:22 by ebenoist          #+#    #+#              #
#    Updated: 2025/07/24 13:43:08 by ebenoist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc -g
CFLAGS	= -Wall -Werror -Wextra -g -Ilibft/includes -Iincludes

SRC		=	srcs/main.c\
			srcs/error.c\
			srcs/path_arg.c\
			srcs/test_arg.c\

OBJ		= $(SRC:.c=.o)

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

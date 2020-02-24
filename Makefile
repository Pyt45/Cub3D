# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 20:19:58 by aaqlzim           #+#    #+#              #
#    Updated: 2020/02/22 20:10:22 by aaqlzim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = cub3D

NAMA = cub3d.a

LIBFT = ./libft

LIBFT_LIB = ./libft/libft.a

SRC = src/cub_tools.c \
	  src/cub_tools1.c \
	  src/cub_tools2.c \
	  src/cub_tools3.c \
	  src/cub_tools4.c \
	  src/design_game.c \
	  src/get_next_line.c \
	  src/get_next_line_utils.c \
	  src/handle_key.c \
	  src/handle_map.c \
	  src/handle_move.c \
	  src/handle_pars.c \
	  src/handle_save.c \
	  src/handle_texture.c \
	  src/main.c \
	  src/cub_tools5.c

OBJ = ${SRC:.c=.o}

all:	$(NAME) 

$(LIBFT_LIB):
	@make -C $(LIBFT)

$(NAME): $(OBJ) $(LIBFT_LIB)
	@ar rc $(NAMA) $(OBJ)
	@gcc $(CFLAGS) $(NAMA) $(LIBFT_LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo 'SUCCESS!'

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -f $(LIBFT)/*.o

fclean: clean
	@rm -f $(NAME) rm -f $(NAMA) $(LIBFT_LIB)

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/10 13:58:49 by abdait-m          #+#    #+#              #
#    Updated: 2020/11/16 17:55:32 by abdait-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIB = libcub3d.a

MAIN = cub3d.c

FILES = $(wildcard ./SRCs/*.c)

FILES_B = $(wildcard ./CUB3D_bonus/SRCs/*.c)

HEADER = cub3d.h

OBJECT = $(FILES:.c=.o)

OBJECT_B = $(FILES_B:.c=.o)

FLAGS = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJECT) $(HEADER)
	@mv *.o ./SRCs
	@ar -rcs $(LIB) $(OBJECT)
	@gcc  $(FLAGS) $(MAIN) $(LIB) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\n\033[36m***** YOU MAY START YOUR GAME NOW ***** \033[0m\n"
	
bonus: all

%.o:%.c $(HEADER)
	@gcc -c $< $(FLAGS)

clean:
	@rm -rf srcs/*.o $(LIB)
	@echo "\n\033[32mCleaning is Done!\033[0m\n"

fclean: clean
	@rm -rf $(NAME)

re : fclean all
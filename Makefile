# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 22:33:58 by tpokalch          #+#    #+#              #
#    Updated: 2019/02/20 23:11:55 by tpokalch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJ = line_to_image.o main.o create_points.o project.o free_points.o initialize_points.o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -g -Wall -Wextra -Werror -I libft/includes -o line_to_image.o -c line_to_image.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o create_points.o -c create_points.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o project.o -c project.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o free_points.o -c free_points.c
	clang -g -Wall -Wextra -Werror -I libft/includes -o initialize_points.o -c initialize_points.c	
	clang -g -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	gcc -I /usr/local/include $(OBJ) -o fdf -L /usr/local/lib/ -lmlx -L ./libft -lft -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

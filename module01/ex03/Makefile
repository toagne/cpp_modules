# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 13:42:12 by mpellegr          #+#    #+#              #
#    Updated: 2025/01/15 19:23:19 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:.cpp=.o)
NAME = Unnecessary_violence
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
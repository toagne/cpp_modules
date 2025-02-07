# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 11:19:07 by mpellegr          #+#    #+#              #
#    Updated: 2025/02/07 09:08:35 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
NAME = RPN
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++11
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
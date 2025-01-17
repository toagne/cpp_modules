# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 17:42:16 by mpellegr          #+#    #+#              #
#    Updated: 2025/01/17 10:09:05 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)
NAME = harlFilter
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